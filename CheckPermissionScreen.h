#pragma once
#include "Screen.h"
#include "User.h"
#include "Permissions.h"
#include "PermissionsManager.h"
#include "ChangeOutputColor.h"
class CheckPermissionScreen :
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
        cout << "8- Full\n";
        cout << "----------------------------------------\n";

        int choice = clsInputValidation::getNumber(message);

        while (!clsInputValidation::isNumberBetween(choice, 1, 8))
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
        case 8: return Permissions::Full;
        default: return Permissions::None;
        }
    }
public:
    static void showCheckPermissionScreen(User u)
    {
        drawScreenHeader("Check Permission Screen");
        Permissions p = getPermission("What Permission Do you want to Check if the user have it?");
        if (PermissionsManager::hasPermission(u, p))
        {
            cout << ChangeOutputColor::setGreen("The User has this permission.") << endl;
        }
        else
            cout << ChangeOutputColor::setRed("The User does not have this permission!") << endl;
        system("pause");
    }
};

