#pragma once
#include "Screen.h"
#include <iostream>
#include "TransactionsManager.h"
class DepositeScreen: public Screen
{
public:
	static void showDepositeScreen()
	{
		drawScreenHeader("Deposite Screen");
		TransactionsManager::deposite();
	}
};

