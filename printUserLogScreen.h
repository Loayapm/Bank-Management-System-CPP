#pragma once
#include "Screen.h"
#include "clsInputValidation.h"
#include "UsersManager.h"
#include "Logger.h"
class printUserLogScreen :
    protected Screen
{
public:
    static void showPrintUserLogScreen()
    {
        drawScreenHeader("Print User Log Records");
        string username = clsInputValidation::readString("Enter the Username for the user to print their Log History");
        if (!(UsersManager::isUserExists(username)))
        {
            cout << "No User Found With this Username" << endl;
            return;
        }
        Logger::printLogs(username);
        system("pause");
    }

};

