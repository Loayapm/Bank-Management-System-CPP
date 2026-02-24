// Bank.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Client.h"
#include "ClientsManager.h"
#include "MainScreen.h"
#include "TransactionsManager.h"
#include "UsersManager.h"
#include "LoginScreen.h"
#include "Session.h"
#include "TransactionLogger.h"
#include "PasswordHasher.h"

int main()
{
	
	UsersManager::loadUsersFromFile();
	
	//the vector is full with the users, now i need to update the passwords with the hashed ones
	
	
	point:
	LoginScreen::showLoginScreen();
	if (Session::returnLoginState() == true)
	{
		
		ClientsManager::loadClientsFromFile();
		MainScreen::showMainMenue();
		goto point;
	}
	
	
}

