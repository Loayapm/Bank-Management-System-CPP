#pragma once
#include "Screen.h"
#include "clsInputValidation.h"
#include "User.h"
#include "UsersManager.h"
#include "ChangeOutputColor.h"
class FindUserScreen :
    protected Screen
{
public:
    static void ShowFindUserScreen()
    {
        string username = clsInputValidation::readString("Enter the username for the user you want to find: ");
        if (!(UsersManager::isUserExists(username)))
        {
            cout <<ChangeOutputColor::setRed( "There is no user with this Username: ") << endl;
            return;
        }
        cout << ChangeOutputColor::setGreen("User found")<<endl;
        User userToPrint = UsersManager::findUser(username);
        userToPrint.printUser();
        system("pause");
    }
};

