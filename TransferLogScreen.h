#pragma once
#include "Screen.h"
#include "TransactionLogger.h"
class TransferLogScreen :
    protected Screen
{
public:
    static void showTransferLogScreen()
    {
        drawScreenHeader("Transfer Log");
        TransactionLogger::printTransferLogs();
	}
};

