#pragma once
#include "Screen.h"
#include "Logger.h"
class printLogScreen :
    private Screen
{
public:
    static void showPrintLogScreen()
    {
        drawScreenHeader("Print Complete Log Screen");
        Logger::printLogs();
        system("pause");
    }
};

