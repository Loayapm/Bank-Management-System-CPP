#pragma once
#include "Screen.h"
#include "TransactionsManager.h"

class WithdrawlScreen : Screen
{
public:
	static void showWithdrwalScreen()
	{
		drawScreenHeader("Withdrawl Screen");
		TransactionsManager::withdrawl();
	}
};

