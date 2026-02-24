#pragma once
#include "Screen.h"
#include "ClientsManager.h"
class UpdateClientScreen : public Screen
{
public: 
	static void showUpdateClientScreen()
	{
		drawScreenHeader("Update Client Screen");
		ClientsManager::updateClientInfo();
	}
};

