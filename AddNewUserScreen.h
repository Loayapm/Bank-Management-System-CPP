#pragma once
#include "Screen.h"
#include "UsersManager.h"
class AddNewUserScreen :
    protected Screen
{
public:
    static void showAddNewUserScreen()
    {
        drawScreenHeader("Add New User Screen");
        UsersManager::addNewUser();
    }
};

