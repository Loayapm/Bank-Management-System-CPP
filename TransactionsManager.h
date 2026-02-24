#pragma once
#include "clsInputValidation.h"
#include "Client.h"
#include "ClientsManager.h"
#include "ChangeOutputColor.h"
#include "TransactionLogger.h"
#include "Session.h"
class TransactionsManager
{
public:
	/// <summary>
	/// I need to keep the logic here and move the prints to the UI, I think.
	/// </summary>
	static void deposite()
	{
		string accountNumber = clsInputValidation::readString("Enter the account number for the client you want to deposite for.");
		Client clientToDepositeFor=ClientsManager::findClientByAccountNumber(accountNumber);
		if (clientToDepositeFor.isEmpty())
		{
			cout << ChangeOutputColor::setRed( "No client found with this account number!") << endl;
			system("pause");

			return;
		}
		clientToDepositeFor.Print();

		float totalBalance = clsInputValidation::getFloat("How much you want to deposite?") + clientToDepositeFor.getBalance();
		ClientsManager::updateClientBalance(accountNumber, totalBalance);
		cout << ChangeOutputColor::setGreen("Balance updated successfully" )<< endl;
		cout << "Press any key to return to the main screen" << endl;
		system("pause");
	}

	static void withdrawl()
	{
		string accountNumber = clsInputValidation::readString("Enter the account number for the client you want to withdraw from.");
		Client client = ClientsManager::findClientByAccountNumber(accountNumber);
		if (client.isEmpty())
		{
			cout << ChangeOutputColor::setRed("No client found with this account number.") << endl;
			system("pause");

			return;
		}

		client.Print();
		float withdrawlAmount = clsInputValidation::getFloat("How much do you want to withdraw?");
		if (withdrawlAmount > client.getBalance())
		{
			cout << ChangeOutputColor::setRed ("No enough balance") << endl;
			system("pause");
			return;
		}

		float newBalance = client.getBalance() - withdrawlAmount;
		ClientsManager::updateClientBalance(accountNumber, newBalance);
		cout << ChangeOutputColor::setGreen("Balance updated successfully") << endl;
		cout << "Press any key to return to the main screen" << endl;
		system("pause");
	}

	static void Transfer()
	{
		string accFrom = clsInputValidation::readString("Enter the Account Number For the Client You want to Transfer From: ");
		Client client = ClientsManager::findClientByAccountNumber(accFrom);

		if (client.isEmpty())
		{
			cout << ChangeOutputColor::setRed("No client found with this account number.") << endl;
			system("pause");

			return;
		}
		client.Print();
		int amount = clsInputValidation::readDouble("How much do you want to transfer?");
		if (amount > client.getBalance())
		{
			cout << ChangeOutputColor::setRed("No enough balance");
			return;
		}

		string accTo = clsInputValidation::readString("Enter the Account Number For the Client You want to Transfer From: ");
		Client client2 = ClientsManager::findClientByAccountNumber(accTo);

		if (client2.isEmpty())
		{
			cout << ChangeOutputColor::setRed("No client found with this account number.") << endl;
			system("pause");

			return;
		}
		client2.Print();
		double newBalanceFrom = client.getBalance() - amount;
		double newBalanceTo = client2.getBalance() + amount;
		ClientsManager::updateClientBalance(accFrom, newBalanceFrom);
		ClientsManager::updateClientBalance(accTo, newBalanceTo);
		cout << ChangeOutputColor::setGreen("Transfer has been made successfully.") << endl;
		system("pause");
		//now I need to log the transfer
		User u = Session::returnCurrentUser();
		TransactionLogger::logTransfer(accFrom, accTo, amount,newBalanceFrom,newBalanceTo,u.getUsername());
	}
};

