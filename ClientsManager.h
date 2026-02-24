#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <fstream>
#include "Client.h"
#include "string"
#include "clsInputValidation.h"
#include <iomanip>
#include "Utility.h"
class ClientsManager
{
	private:
		static vector<Client> clientsVector;
	//load clients from file
public:
	static void loadClientsFromFile()
	{
		clientsVector.clear();
		ifstream clientsFile("D:\\Clients.txt");
		if (!clientsFile.is_open())
		{

			cout << "Cannot open file!" << endl;
			return;
		}
		string line;
		while (getline(clientsFile,line))
		{
			//send the line in the text file to the SplitString function
			Client client = SplitString(line, "#//#");
			clientsVector.push_back(client);
		}
		
	}

	static void saveClientsToFile()
	{
		ofstream clientsFile("D:\\Clients.txt");
		if (!clientsFile.is_open())
		{
			cout << "Cannot open file!" << endl;
			return;
		}
		for (const auto& client : clientsVector)
		{
			clientsFile << client.getFname() << "#//#"
						<< client.getLname() << "#//#"
						<< client.getPhoneNumber() << "#//#"
						<< client.getEmail() << "#//#"
						<< client.getAccountNumber() << "#//#"
						<< client.getPinCode() << "#//#"
						<< client.getBalance() << endl;
		}
		clientsFile.close();
	}
	static Client SplitString(const string & line, const string & delimiter)
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

		Client client(
			Client::clientMode::UpdateMode,
			tokens[0],
			tokens[1],
			tokens[2],
			tokens[3],
			tokens[4],
			tokens[5],
			stod(tokens[6])
		);
		return client;
	}
	static Client findClientByAccountNumber(const string& accountNumber)
	{
		for (const auto& client : clientsVector)
		{
			if (client.getAccountNumber() == accountNumber)
			{
				return client;
			}
		}
		// Return an empty client if not found
		return Client(Client::clientMode::EmptyMode, "", "", "", "", "", "", 0.0);
	}
	//i need to get the new client information and update it in the file
	static void updateClientInfo()
	{
		string accountNumber = clsInputValidation::readString("Enter account number of the client to update:");
		Client clientToUpdate = findClientByAccountNumber(accountNumber);
		while (clientToUpdate.isEmpty())
		{
			cout << "Client not found!" << endl;
			accountNumber = clsInputValidation::readString("Enter account number of the client to update:");
		    clientToUpdate = findClientByAccountNumber(accountNumber);
		}
		clientToUpdate.Print();
		if (!clsInputValidation::getConfirmation("Do you want to update this client? y/n"))
			return;

		clientToUpdate.fillClientInfo(clientToUpdate);
		// Now, update the client in the clients vector
		for (Client & client : clientsVector)
		{
			if (client.getAccountNumber() == accountNumber)
			{
				client = clientToUpdate;
				cout << "Client information updated successfully." << endl;
				break;
			}
		}
		//now i need to save the updated clientsVector to the file
		saveClientsToFile();
	}
	static bool isClientExist(string accountNumber)
	{
		Client cl = findClientByAccountNumber(accountNumber);
		return !(cl.isEmpty());
	}

	static void addNewClient()
	{
		Client newClient(Client::clientMode::UpdateMode, "", "", "", "", "", "", 0.0);
		newClient.fillClientInfo(newClient);
		newClient.setAccountNumber(clsInputValidation::readString("Enter Account Number:"));
		if (isClientExist(newClient.getAccountNumber()))
		{
			cout << "Client with this account number already exists!" << endl;
			return;
		}
		clientsVector.push_back(newClient);
		saveClientsToFile();
	}
	static int findClientIndex(Client client)
	{
		for (int i = 0; i < clientsVector.size(); i++)
		{
			if (clientsVector[i].getAccountNumber() == client.getAccountNumber())
			{
				return i;
			}
		}
	}
	static void updateClientBalance(string accountNumber, int newBalance)
	{
		Client clientToUpdate = findClientByAccountNumber(accountNumber);
		int index = findClientIndex(clientToUpdate);
		clientToUpdate.setBalance(newBalance);
		clientsVector[index] = clientToUpdate;
		saveClientsToFile();
	}
	static void deleteClient()
	{
		Client clientToDelete = findClientByAccountNumber(clsInputValidation::readString("Enter the account number for the client you want to delete: "));
		point:
		if (!isClientExist(clientToDelete.getAccountNumber()))
		{
			cout << "Client with this account number does not exist!" << endl;
			goto point;
		}
		clientToDelete.Print();
		if (!clsInputValidation::getConfirmation("Are you sure you want to delete this client? y/n"))
			return;
		for (Client & client : clientsVector)
		{
			if (clientToDelete.getAccountNumber() == client.getAccountNumber())
			{
				int index = findClientIndex(client);
				clientsVector.erase(clientsVector.begin() + index);
			}
			//now i need to save the updated clientsVector to the file
			saveClientsToFile();
		}

	}
	static void printAllClients()
	{
		cout << "All Clients:\n" << endl;
	
		cout << left << "| " << setw(15) << "AccountNumber"
			<< left << "| " << setw(17) << "FullName"
			<< left << "| " << setw(20) << "PhoneNumber"
			<< left << "| " << setw(30) << "Email"
			<< left << "| " << setw(10) <<"Pin Code"
			<< left << "| " << setw(10) << "Balance" << endl;
		cout << "----------------------------------------------------------------------------------------------------------------" << endl;
		for (const auto& client : clientsVector)
		{
			cout<<left<< "| " << setw(15)<< client.getAccountNumber()
				<< left << "| " << setw(17) << client.getFullName()
				<< left << "| " << setw(20) << client.getPhoneNumber()
				<< left << "| " << setw(30) << client.getEmail()
				<< left << "| " << setw(10) << client.getPinCode()
				<< left << "| " << setw(10) << client.getBalance() << endl;
		}
		cout << "----------------------------------------------------------------------------------------------------------------"<< endl;
	}

	static void showAllBalances()
	{
		cout << "------------------------------------------------------------------------------------------------------" << endl;

		cout << left << "| " << setw(15) << "AccountNumber"
			<< left << "| " << setw(17) << "FullName"
			<< left << "| " << setw(10) << "Balance" << endl;
		cout << "------------------------------------------------------------------------------------------------------" << endl;

		for (const auto & client : clientsVector)
		{
			cout << left << "| " << setw(15) << client.getAccountNumber()
				<< left << "| " << setw(17) << client.getFullName()
				<< left << "| " << setw(10) << client.getBalance() << endl;
		}
		cout << "------------------------------------------------------------------------------------------------------" << endl;

		double totalBalances = 0;
		for (Client client : clientsVector)
		{
			totalBalances += client.getBalance();
		}
		cout << "Total Balances = " << totalBalances<<" "<< Utility::numberToWords(totalBalances)<<endl;
		cout << "------------------------------------------------------------------------------------------------------" << endl;
		cout << "Press any key to return to the main screen" << endl;
		system("pause");
	}

	static int countClients()
	{
		return clientsVector.size();
	}
	
};

