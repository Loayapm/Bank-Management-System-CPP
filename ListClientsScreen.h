#pragma once
#include "Screen.h"
#include "ClientsManager.h"
class ListClientsScreen : protected Screen
{
public:
	static void showListClientsScreen()
	{
		int noc = ClientsManager::countClients();
		drawScreenHeader("List Clients Screen","Number of clients: "+to_string(noc));
		ClientsManager::printAllClients();
		cout << "Press any key to return to the main menue." << endl;
		system("pause");
	}

};

