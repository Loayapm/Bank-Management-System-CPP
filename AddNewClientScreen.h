#pragma once
#include "Screen.h"
#include "ClientsManager.h"

class AddNewClientScreen : protected Screen
{
public:
	static void showAddNewClientScreen()
	{
		drawScreenHeader("Add New Client Screen");
		ClientsManager::addNewClient();
	}
};

