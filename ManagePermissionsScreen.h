#pragma once
#include "Screen.h"
#include <iomanip>
#include "UsersManager.h"
#include "User.h"
#include "clsInputValidation.h"
#include "GrantPermissionScreen.h"
#include "RevokePermissionScreen.h"
#include "ClearPermissionsScreen.h"
#include "ListPermissionsScreen.h"
#include "CheckPermissionScreen.h"
#include "ChangeOutputColor.h"

class ManagePermissionsScreen :
    protected Screen
{
public:
    enum class managePermissionsOptions
    {
        Grant = 1,
        Revoke = 2,
        Clear = 3,
        List = 4,
        Check = 5,
        Return = 6
    };
 
    static bool peformManageUsersPermissions(managePermissionsOptions option,User & u)
    {
        bool returnToUsersManager=false;
        switch (option)
        {
            case managePermissionsOptions::Grant:
                GrantPermissionScreen::showGrantPermissionScreen(u);
                UsersManager::replaceUser(u);
                break;
            case managePermissionsOptions::Revoke:
                RevokePermissionScreen::showRevokePermissionsScreen(u);
                UsersManager::replaceUser(u);
                break;
            case managePermissionsOptions::Clear:
                ClearPermissionsScreen::showClearPermissionsScreen(u);
                UsersManager::replaceUser(u);
                break;
            case managePermissionsOptions::List:
                ListPermissionsScreen::showListPermissionsScreen(u);
                break;
            case managePermissionsOptions::Check:
                CheckPermissionScreen::showCheckPermissionScreen(u);
               
                break;
            case managePermissionsOptions::Return:
                returnToUsersManager = true;
                break;
        }
        return returnToUsersManager;
    }
public :
    static void showManagePermisssionsScreen()
    {
        //first, find the user to change thier permissions
        string username = clsInputValidation::readString("Enter Username for the User: ");
        User u = UsersManager::findUser(username);
        while (true)
        {
            if (!u.isEmptyUser())
                break;
            else
            {
                username = clsInputValidation::readString("No user found!\n Enter Username again: ");
                u = UsersManager::findUser(username);
            }
        }
        if (u.getUsername() == "admin")
        {
            cout << ChangeOutputColor::setRed("Cannot change the admin permissions!") << endl;
            system("pause");
            return;
        }
        User currentUser = Session::returnCurrentUser();
        if (u.getUsername() == currentUser.getUsername())
        {
            cout << ChangeOutputColor::setRed("You Cannot Change You Permissions, Ask the Admin To Do So") << endl;
            system("pause");
            return;
        }
       
        cout << ChangeOutputColor::setGreen("User Found. You can continue" )<< endl;
        system("pause");
        while (true)
        {
            system("cls");
            drawScreenHeader("Manage User Permissions Screen");
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "         Manage User Permissions Menu\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] Grant Permissions.\n";
            cout << setw(37) << left << "" << "\t[2] Revoke Permissions.\n";
            cout << setw(37) << left << "" << "\t[3] Clear Permissions.\n";
            cout << setw(37) << left << "" << "\t[4] List User Permissions.\n";
            cout << setw(37) << left << "" << "\t[5] Check User Permissions.\n";
            cout << setw(37) << left << "" << "\t[6] Return to Manage Users Screen.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            int option = clsInputValidation::getNumber("What do you want to choose? 1-6");
            while (true)
            {
                if (clsInputValidation::isNumberBetween(option, 1, 6))
                    break;
                else
                {
                    option = clsInputValidation::getNumber("Wrong input!\nWhat do you want to choose? 1-6");
                }
            }
            bool returnToUsersScreen;

            returnToUsersScreen = peformManageUsersPermissions(static_cast<managePermissionsOptions>(option), u);
            if (returnToUsersScreen)
                break;
        }
    }
};

