#pragma once
#include "Screen.h"
#include "Permissions.h"
#include "PermissionsManager.h"
#include "ChangeOutputColor.h"
class RevokePermissionScreen :
    protected Screen
{

    static Permissions getPermission(const string & message)
    {
        cout << "----------------------------------------\n";
        cout << "List Of Permissions:\n";
        cout << "1- ListClients\n";
        cout << "2- AddNewClient\n";
        cout << "3- DeleteClient\n";
        cout << "4- UpdateClient\n";
        cout << "5- FindClient\n";
        cout << "6- Transactions\n";
        cout << "7- ManageUsers\n";
        cout << "8- ShowLogs\n";
        cout << "9- Full\n";
        cout << "----------------------------------------\n";

        int choice = clsInputValidation::getNumber(message);

        while (!clsInputValidation::isNumberBetween(choice, 1, 9))
        {
            choice = clsInputValidation::getNumber("Wrong input!\n" + message);
        }

        switch (choice)
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
    static void showRevokePermissionsScreen(User &u)
    {
        drawScreenHeader("Revoke Permission Screen");
        Permissions p = getPermission("What Permission Do you Want To Revoke? 1-9");
        if (PermissionsManager::revokePermission(u, p))
            cout << ChangeOutputColor::setGreen( "Permission Revoked successfully" )<< endl;
        else cout << ChangeOutputColor::setRed("Permission already revoked!")<< endl;
        system("pause");

    }
};

