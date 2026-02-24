#pragma once
#include "Screen.h"
#include "clsInputValidation.h"
#include "printLogScreen.h"
#include "printUserLogScreen.h"
class LogShowScreen :
    protected Screen
{
public:
    enum class LogOptions{PrintLog=1,PrintLogForUser=2};
    static void clearScreen()
    {
        system("cls");
    }
    static void performShowLogScreen(LogOptions option)
    {
        switch (option)
        {
        case LogOptions::PrintLog:
            clearScreen();
            printLogScreen::showPrintLogScreen();
            break;
        case LogOptions::PrintLogForUser:
            clearScreen();
            printUserLogScreen::showPrintUserLogScreen();
            break;

        }
    }
    static void showLogShowScreen()
    {
        drawScreenHeader("Log Show Screen");
        cout << left << setw(37) << "\t\t\t\t[1] Print Complete Log." << endl;
        cout << left << setw(37) << "\t\t\t\t[2] Print Log for User." << endl;
        int option = clsInputValidation::getNumber("What do you want to do? 1-2");
        while (true)
        {
            if (clsInputValidation::isNumberBetween(option, 1, 2))
            {
                break;
            }
            else option = clsInputValidation::getNumber("Wrong input! Enter Number Again");
        }
        performShowLogScreen(static_cast<LogOptions>(option));

    }


};

