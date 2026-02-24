#pragma once
#include "Screen.h"
#include "ClientsManager.h"
#include "Client.h"
class FindClientScreen : protected Screen
{
public:
	static void showFindClientScreen()
	{
		drawScreenHeader("Find Client Screen");
		string accountNumber = clsInputValidation::readString("Enter account number of the client to find:");
		Client cl=ClientsManager::findClientByAccountNumber(accountNumber);
		cl.Print();
	}
};

