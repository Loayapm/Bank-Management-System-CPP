#pragma once
#include "Screen.h"
#include "UsersManager.h"
class ListUsersScreen :
    protected Screen
{
public:
    static void showListUsersScreen()
    {
        int nou = UsersManager::countUsers();
        string st = "There are " + to_string(nou) + " Users.";
        drawScreenHeader("List Users Screen",st);
        UsersManager::listUsers();
        system("pause");
        cout << "Press any key to return to the Manage Users Screen" << endl;

    }
};

