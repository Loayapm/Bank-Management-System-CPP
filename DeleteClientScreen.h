#pragma once
#include "Screen.h"
#include "ClientsManager.h"
class DeleteClientScreen : protected Screen
{
public:
	static void showDeleteClientScreen()
	{
		drawScreenHeader("Delete Client Screen");
		ClientsManager::deleteClient();
	}
};

