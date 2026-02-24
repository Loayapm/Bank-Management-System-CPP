#pragma once
using namespace std;
#include "User.h"
#include "clsInputValidation.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
#include "PermissionsManager.h"
#include "ChangeOutputColor.h"
#include "PasswordHasher.h"
class UsersManager
{
private:
	static vector <User> UsersVector;
public:
	static bool usernameExists(string u)
	{
		for (User user : UsersVector)
		{
			return user.getUsername() == u;
		}
		return false;
	}
	static bool isUserExists(string username)
	{
		for (User u : UsersVector)
		{
			if (u.getUsername() == username)
				return true;
		}
		return false;
	}
	static void addNewUser()
	{
		
		string fname = clsInputValidation::readString("Enter First Name: ");
		string lname = clsInputValidation::readString("Enter Last Name: ");
		string phoneNumber = clsInputValidation::readString("Enter Phone Number: ");
		string email = clsInputValidation::readString("Enter Email: ");
	
		
		string userName;
	
		while(true)
		{
			 userName = clsInputValidation::readString("Enter Username: ");

			if (!usernameExists(userName))
				break;
			cout << ChangeOutputColor::setRed("This username is already used, try another one.") << endl;
		}

		
		string password = clsInputValidation::readString("Enter Password: ");
		int permissions = 0;
		User::enUserMode mode = User::enUserMode::AddNewMode;
		string salt = PasswordHasher::generateSalt();
		string hashedPassword = PasswordHasher::hashPassword(password, salt);
		User user(fname, lname, phoneNumber, email, mode, userName,salt, hashedPassword, permissions);
		//User u("",)
		UsersVector.push_back(user);

		char grantpermission = clsInputValidation::readChar("Do you want to give this user any Permisison/s?");
		if (grantpermission == 'y' || grantpermission == 'Y')
		{
			char grantFull = clsInputValidation::readChar("Do you want to grant Full Permissions?");
			if (grantFull == 'y' || grantFull == 'Y')
			{
				PermissionsManager::grantPermission(user, Permissions::Full);
				return;
			}
			char grantList = clsInputValidation::readChar("Do you want to grant List Clients Permission?");
			if (grantList == 'y' || grantList == 'Y') PermissionsManager::grantPermission(user, Permissions::ListClients);
			char grantAdd = clsInputValidation::readChar("Do you want to grant Add New Client Permission?");
			if (grantAdd == 'y' || grantAdd == 'Y') PermissionsManager::grantPermission(user, Permissions::AddNewClient);
			char grantDelete = clsInputValidation::readChar("Do you want to grant Delete Client Permission?");
			if (grantDelete == 'y' || grantDelete == 'Y') PermissionsManager::grantPermission(user, Permissions::DeleteClient);
			char grantUpdate = clsInputValidation::readChar("Do you want to grant Update Client Permission?");
			if (grantUpdate == 'y' || grantUpdate == 'Y') PermissionsManager::grantPermission(user, Permissions::UpdateClient);
			char grantFind = clsInputValidation::readChar("Do you want to grant Find Client Permission?");
			if (grantFind == 'y' || grantFind == 'Y') PermissionsManager::grantPermission(user, Permissions::FindClient);
			char grantTransactions = clsInputValidation::readChar("Do you want to grant Manage Transactions Permission?");
			if (grantTransactions == 'y' || grantTransactions == 'Y') PermissionsManager::grantPermission(user, Permissions::Transactions);
			char grantManageUsers = clsInputValidation::readChar("Do you want to grant Manage Users Permission?");
			if (grantManageUsers == 'y' || grantManageUsers == 'Y') PermissionsManager::grantPermission(user, Permissions::ManageUsers);
			replaceUser(user);
			
		}
		loadUsersToFile();
		cout << ChangeOutputColor::setGreen("User Added Successfully!") << endl;
		system("pause");
		
	}
	static int findUserIndex(string username)
	{
		int i = 0;
		for (User u : UsersVector)
		{
			if (u.getUsername() == username)
			{
				return i;
			}
			i++;
		}
		return -1;
	}
	static bool deleteUser(User userToDelete)
	{
		if (userToDelete.getUsername() == "admin")
		{
			return false;
		}
		
		for (User u : UsersVector)
		{
			
			
			if (u.getUsername() == userToDelete.getUsername())
			{
				
				int index = findUserIndex(userToDelete.getUsername());
			
				UsersVector.erase(UsersVector.begin() + index);
			
			}
		
		}
		//now i need to save the updated usersVector to the file
		loadUsersToFile();
		return true;

	}

	static void updateUser(User userToUpdate)
	{
		
		User updatedUser = findUser("");
		updatedUser.setUsername(userToUpdate.getUsername()); // keep the username unchanged.
		updatedUser.setPersmissions(userToUpdate.getPermissions());// keep the permissions unchanged.
		string salt = userToUpdate.getSalt();
		updatedUser.setSalt(salt);//keep the salt unchanged.
		string fname = clsInputValidation::readString("Enter the New First Name:  ");
		updatedUser.setFname(fname);
		string lname = clsInputValidation::readString("Enter the New Last Name: ");
		updatedUser.setLname(lname);
		string phoneNumber = clsInputValidation::readString("Enter the New PhoneNumber: ");
		updatedUser.setPhoneNumber(phoneNumber);
		string email = clsInputValidation::readString("Enter the New Email: ");
		updatedUser.setEmail(email);
		string password = clsInputValidation::readString("Enter the New Password: ");
		//hash the password
		string hashedPassword=PasswordHasher::hashPassword(password, salt);
		updatedUser.setPassword(hashedPassword);
		replaceUser(updatedUser);
		loadUsersToFile();

	}

	static User SplitString(const string & line, const string & delimiter)
	{
		vector<string> tokens;
		size_t start = 0;
		size_t end;

		while ((end = line.find(delimiter, start)) != string::npos)
		{
			tokens.push_back(line.substr(start, end - start));
			start = end + delimiter.length();
		}

		// last token
		tokens.push_back(line.substr(start));
		
		User user(
			
			tokens[0],
			tokens[1],
			tokens[2],
			tokens[3],
			User::enUserMode::UpdateMode,
			tokens[4],
			tokens[5],
			tokens[6],
			stoul(tokens[7])
		);
		return user;
	}
	static void loadUsersFromFile()
	{
		UsersVector.clear();
		ifstream UsersFile("D:\\Users.txt");
		if (!UsersFile.is_open())
		{
			cout << "Cannot load Users file!" << endl;
			return;
		}
		string line;
		while (getline(UsersFile, line))
		{
			User u = SplitString(line, "#//#");
			UsersVector.push_back(u);
		}
	}

	static void loadUsersToFile()
	{
		ofstream usersFile("D:\\Users.txt");
		if (!usersFile.is_open())
		{
			cout << "Cannot open users file!" << endl;
			return;
		}
		for (User u : UsersVector)
		{
			usersFile << u.getFname() << "#//#"
				<< u.getLname() << "#//#"
				<< u.getPhoneNumber() << "#//#"
				<< u.getEmail() << "#//#"
				<< u.getUsername() << "#//#"
				<< u.getSalt()<<"#//#"
				<< u.getPassword() << "#//#"
				<< u.getPermissions() << endl;
		}
		
	}
	static int setUserPermissions()
	{
		//for later
	}
	
	static User findUser(string username)
	{
		int index = findUserIndex(username);
		if (index == -1)
		{
			User u = User::returnEmptyUser();
			return u;
		}
		return UsersVector[index];
	}
	static void replaceUser(User u)
	{
		for (User & user : UsersVector)
		{
			if (user.getUsername() == u.getUsername())
			{
				user = u;
			}
		} // I need to rewrite the file
		loadUsersToFile();
	}
	static User findUserWithUsernameAndPassword(string username, string inputPassword)
	{
		if (!(isUserExists(username)))//no user found with this username
		{
			User u = User::returnEmptyUser();
			return u;
		}
		User user = findUser(username);
		string salt = user.getSalt();
		string hashedPassword = user.getPassword();

		for (User u : UsersVector)
		{
			if (u.getUsername() == username && (PasswordHasher::varifyPassword(inputPassword, hashedPassword, salt)))
			{
				return u;
			}

		}
		User u = User::returnEmptyUser();
		return u;
		
	}
	static void listUsers()
	{
		cout << "-------------------------------------------------------------------------------------------------------------" << endl;
		cout << left << "| " << setw(15) << "Full Name"
			<< left << "| " << setw(17) << "Phone Number"
			<< left << "| " << setw(20) << "Email"
			<< left << "| " << setw(20) << "Username"
			<< left << "| " << setw(15) << "Password"
			<< left << "| " << setw(10) << "Permission" << endl;
		cout << "-------------------------------------------------------------------------------------------------------------" << endl;

		for (User user : UsersVector)
		{
			cout << left << "| " << setw(15) << user.getFullName()
				<< left << "| " << setw(17) << user.getPhoneNumber()
				<< left << "| " << setw(20) << user.getEmail()
				<< left << "| " << setw(20) << user.getUsername()
				<< left << "| " << setw(15) << user.getPassword()
				<< left << "| " << setw(10) << user.getPermissions() << endl;
		}

		cout << "\n\n\n" << endl;
	}
	static int countUsers()
	{
		return UsersVector.size();
	}

	static void replacePasswordWithHashedOnes()
	{
		for (User &u : UsersVector)
		{
			string password = u.getPassword();
			string salt = u.getSalt();
			string newPassword = PasswordHasher::hashPassword(password, salt);
			u.setPassword(newPassword);
		}
		loadUsersToFile();
		cout << "Passwords repalced successfully!" << endl;
		system("pause");
	}
};

