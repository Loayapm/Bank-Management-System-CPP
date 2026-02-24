#pragma once
#include "Screen.h"
#include "PermissionsManager.h"
#include "Permissions.h"
#include "ChangeOutputColor.h"
class ListPermissionsScreen :
    protected Screen
{
    static Permissions getPermission(int i)
    {
       
        switch (i)
        {
        case 1: return Permissions::ListClients;
        case 2: return Permissions::AddNewClient;
        case 3: return Permissions::DeleteClient;
        case 4: return Permissions::UpdateClient;
        case 5: return Permissions::FindClient;
        case 6: return Permissions::Transactions;
        case 7: return Permissions::ManageUsers;
        case 8:return Permissions::ShowLogs;
        case 9: return Permissions::Full;
        default: return Permissions::None;
        }
    }
public:
    static void showListPermissionsScreen(User u)
    {
        
        string permissions[] = {"ListClients","AddNewClient","DeleteClient","UpdateClient","FindClient","Transactions","ManageUsers","ShowLogs","Full"};
      
        uint32_t userPermissions=u.getPermissions();
        drawScreenHeader("List Permissions Screen");
        if (PermissionsManager::hasFullAccess(u))
        {
            cout << ChangeOutputColor::setGreen( "This user has Full access to the system." )<< endl;
            system("pause");
            return;
        }
        else if (userPermissions == 0)
        {
            cout << ChangeOutputColor::setRed("This user has no Permissions") << endl;
            system("pause");
            return;
        } 
        else
        {
            cout << "User Permissions: " << endl;
            for (int i = 1; i < 9; i++)
            {
                if (PermissionsManager::hasPermission(u, getPermission(i)))
                    cout <<"-"<< ChangeOutputColor::setGreen(permissions[i - 1]) << endl;
            }
            system("pause");
        }
       
    }
};

