#pragma once
#include "Screen.h"
#include "TransactionsManager.h"
#include "ClientsManager.h"

class ShowTotalBalanceScreen :
    public Screen
{
public:
    static void showTotalBalanceScreen()
    {
        drawScreenHeader("Total Balance Screen");
        ClientsManager::showAllBalances();
    }
};

