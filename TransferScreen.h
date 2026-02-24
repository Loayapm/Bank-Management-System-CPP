#pragma once
#include "Screen.h"
#include "TransactionsManager.h"
class TransferScreen :
    protected Screen
{
public:
    static void showTransferScreen()
    {
        drawScreenHeader("Transfer Screen");
        TransactionsManager::Transfer();
    }
};

