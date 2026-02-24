#pragma once
#include "Screen.h"
#include <iomanip>
#include "clsInputValidation.h"
#include "ListClientsScreen.h"
#include "AddNewClientScreen.h"
#include "DeleteClientScreen.h"
#include "UpdateClientScreen.h"
#include "FindClientScreen.h"
#include "TransactionScreen.h"
#include "ManageUsersScreen.h"
#include "Permissions.h"
#include "PermissionsManager.h"
#include "Session.h"
#include "ChangeOutputColor.h"
#include "LoginScreen.h"
#include "LogShowScreen.h"
#include "CurrencyExchangeScreen.h"
class MainScreen : protected Screen
{
public:

	static int getMainMenuOption()
	{
		point:
		int option = clsInputValidation::getNumber("What do you want to choos? 1-10");
		
		if (!clsInputValidation::isNumberBetween(option, 1, 10))
		{
			cout << "Invalid input, please enter a number between 1 and 10." << endl;
			goto point;
		}
		return option;
	}

	static void clearScreen()
	{
		
		system("cls");
	}
	static void wait()
	{
		cout << "Press any key to containuou." << endl;
		system("pause");
	}
	enum class enMainMenuOptions{listClients=1, addNewClient=2, deleteClient=3, updateClient=4, findClient=5, transactions=6, manageUsers=7,showLog=8, currencyExchange=9, logout=10};
	static bool performMainMenuOptions(enMainMenuOptions option)
	{
		User currentUser = Session::returnCurrentUser();
		switch (option)
		{
			case enMainMenuOptions::listClients:
				if (!(PermissionsManager::hasPermission(currentUser, Permissions::ListClients)))
				{
					cout << ChangeOutputColor::setRed("You Do Not Have Access To List Clients Feature")<<endl;
					system("pause");
					break;
				}
				clearScreen();
				ListClientsScreen::showListClientsScreen();
				break;
			case enMainMenuOptions::addNewClient:
				if (!(PermissionsManager::hasPermission(currentUser, Permissions::AddNewClient)))
				{
					cout << ChangeOutputColor::setRed("You Do Not Have Access To Add New Client Feature")<<endl;
					system("pause");
					break;
				}
				clearScreen();
				AddNewClientScreen::showAddNewClientScreen();
				break;
			case enMainMenuOptions::deleteClient:
				if (!(PermissionsManager::hasPermission(currentUser, Permissions::DeleteClient)))
				{
					cout << ChangeOutputColor::setRed("You Do Not Have Access To Delete Client Feature")<<endl;
					system("pause");
					break;
				}
				clearScreen();
				DeleteClientScreen::showDeleteClientScreen();
				break;
			case enMainMenuOptions::updateClient:
				if (!(PermissionsManager::hasPermission(currentUser, Permissions::UpdateClient)))
				{
					cout << ChangeOutputColor::setRed("You Do Not Have Access To Update Client Feature")<<endl;
					system("pause");
					break;
				}
				clearScreen();
				UpdateClientScreen::showUpdateClientScreen();
				break;
			case enMainMenuOptions::findClient:
				if (!(PermissionsManager::hasPermission(currentUser, Permissions::FindClient)))
				{
					cout << ChangeOutputColor::setRed("You Do Not Have Access To Find Client Feature")<<endl;
					system("pause");
					break;
				}
				clearScreen();
				FindClientScreen::showFindClientScreen();
				break;
			case enMainMenuOptions::transactions:
				if (!(PermissionsManager::hasPermission(currentUser, Permissions::Transactions)))
				{
					cout << ChangeOutputColor::setRed("You Do Not Have Access To Manage Transactions Feature")<<endl;
					system("pause");
					break;
				}
				clearScreen();
				TransactionScreen::showTransactionScreen();
				break;
			case enMainMenuOptions::manageUsers:
				if (!(PermissionsManager::hasPermission(currentUser, Permissions::ManageUsers)))
				{
					cout << ChangeOutputColor::setRed("You Do Not Have Access To Manage Users Feature")<<endl;
					system("pause");
					break;
				}
				clearScreen();
				ManageUsersScreen::ShowManageUsersMenue();
				break;

			case enMainMenuOptions::showLog:
				if(!(PermissionsManager::hasPermission(currentUser,Permissions::ShowLogs) ))
				{
					cout << ChangeOutputColor::setRed("You Do Not Have Access To Show Logs Feature") << endl;
					system("pause");
					break;
				}
				clearScreen();
				LogShowScreen::showLogShowScreen();
				break;

			case enMainMenuOptions::currencyExchange:
				clearScreen();
				CurrencyExchangeScreen::showCurrencyExchangeScreen();
				break;
			case enMainMenuOptions::logout:
				clearScreen();
				Session::Logout();
				cout << "logged out successfully" << endl;
				return true;
				break;
				
		}
		return false;
	}
    static void showMainMenue()
	{
		
		while (true) 
		{
			
			clearScreen();
			drawScreenHeader("Main Screen");

			cout << left << setw(37) << "\t\t\t\t[1] Show Client List." << endl;
			cout << left << setw(37) << "\t\t\t\t[2] Add New Client." << endl;
			cout << left << setw(37) << "\t\t\t\t[3] Delete Client." << endl;
			cout << left << setw(37) << "\t\t\t\t[4] Update Client Info." << endl;
			cout << left << setw(37) << "\t\t\t\t[5] Find Client." << endl;
			cout << left << setw(37) << "\t\t\t\t[6] Transactions." << endl;
			cout << left << setw(37) << "\t\t\t\t[7] Manage Users." << endl;
			cout << left << setw(37) << "\t\t\t\t[8] Show Logs." << endl;
			cout << left << setw(37) << "\t\t\t\t[9] Currency Exchange." << endl;
			cout << left << setw(37) << "\t\t\t\t[10] Logout." << endl;

			if (performMainMenuOptions((enMainMenuOptions)getMainMenuOption()))
				break;;
		}


	}
};

