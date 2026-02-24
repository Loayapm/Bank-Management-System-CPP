#pragma once
#include "Screen.h"
#include "User.h"
#include "UsersManager.h"
#include "PermissionsManager.h"
class ClearPermissionsScreen :
    protected Screen
{

public:
    static void showClearPermissionsScreen(User & u)
    {
        drawScreenHeader("Clear Permission Screen");
        if (PermissionsManager::clearPermissions(u))
        {
            cout << "Permissions removed successfully" << endl;
        }
        else cout << "There are not permissions to remove!" << endl;
        system("pause");
    }
   
};

