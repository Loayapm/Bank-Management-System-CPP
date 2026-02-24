#pragma once
#include <iostream>
using namespace std;
#include "Person.h"
#include "clsInputValidation.h"
class Client : public Person
{
public:
	enum class clientMode
	{
		EmptyMode = 0, UpdateMode = 1
	};
private:
	//const int Id;
	string accountNumber;
	string pinCode;
	double balance;
	clientMode mode;

public:
	//setters
	void setAccountNumber(string accountNumber)
	{
		this->accountNumber = accountNumber;
	}
	void setPinCode(string pinCode)
	{
		this->pinCode = pinCode;
	}
	void setBalance(double balance)
	{
		this->balance = balance;
	}
	//constructor
	Client(clientMode cmode, string fname, string lname, string email, string phoneNumber, string accountNumber, string pinCode, double balance)
		: Person(fname, lname, phoneNumber, email), mode(cmode), accountNumber(accountNumber), pinCode(pinCode), balance(balance)
	{
	}
	//getters

	//int getId() const
	//{
	//	//return Id;
	//}
	string getAccountNumber() const
	{
		return accountNumber;
	}
	string getPinCode() const
	{
		return pinCode;
	}
	double getBalance() const
	{
		return balance;
	}

	bool isEmpty() const
	{
		return mode==clientMode::EmptyMode;
	}

	void Print()
	{
		cout << "Client Information:" << endl;
		cout << "---------------------------------" << endl;
		cout << "Full Name      : " << getFullName() << endl;
		cout << "Phone Number   : " << getPhoneNumber() << endl;
		cout << "Email          : " << getEmail() << endl;
		cout << "Account Number : " << getAccountNumber() << endl;
		cout << "Pin Code       : " << getPinCode() << endl;
		cout << "Balance        : " << getBalance() << endl;
		cout << "---------------------------------" << endl;
	}
	


	void fillClientInfo(Client & client)
	{
		client.setFname(clsInputValidation::readString("Enter First Name:"));
		client.setLname(clsInputValidation::readString("Enter Last Name:"));
		client.setPhoneNumber(clsInputValidation::readString("Enter Phone Number:"));
		client.setEmail(clsInputValidation::readString("Enter Email:"));
		client.setPinCode(clsInputValidation::readString("Enter Pin Code:"));
		client.setBalance(clsInputValidation::readDouble("Enter Balance:"));

	}
};

