#pragma once
#include "Screen.h"
#include "clsInputValidation.h"
#include "ListUsersScreen.h"
#include "AddNewUserScreen.h"
#include "DeleteUserScreen.h"
#include "UpdateUserScreen.h"
#include "FindUserScreen.h"
#include "ManagePermissionsScreen.h"
class ManageUsersScreen : protected Screen
{
public:
    enum class enManageUsersScreenOptions{ListUsers=1,AddNewUser=2,DeleteUser=3,UpdateUser=4,UpdatePermissions=5,FindUser=6,MainMenu=7};
private:
    enManageUsersScreenOptions option;
    static void clearScreen()
    {
        system("cls");
    }
public:
    static bool performMainMenuOptions(enManageUsersScreenOptions option)
    {
        bool returnToMainMenu = false;
        switch (option)
        {
        case enManageUsersScreenOptions::ListUsers:
            clearScreen();
            ListUsersScreen::showListUsersScreen();
            break;
        case enManageUsersScreenOptions::AddNewUser:
            clearScreen();
            AddNewUserScreen::showAddNewUserScreen();
            break;
        case enManageUsersScreenOptions::DeleteUser:
            clearScreen();
            DeleteUserScreen::ShowDeleteUserScreen();
            break;
        case enManageUsersScreenOptions::UpdateUser:
           UpdateUserScreen::ShowUpdateUserScreen();
            break;
        case enManageUsersScreenOptions::UpdatePermissions:
            clearScreen();
            ManagePermissionsScreen::showManagePermisssionsScreen();
            break;

        case enManageUsersScreenOptions::FindUser:
            clearScreen();
            FindUserScreen::ShowFindUserScreen();
            break;
        case enManageUsersScreenOptions::MainMenu:
            returnToMainMenu = true;
            break;
        }
        return returnToMainMenu;

	}

    static int ReadManageUsersMenueOption()
    {
		int option = clsInputValidation::getNumber("What do you want to choose? [1 to 7]?");
        while (true)
        {
			if (clsInputValidation::isNumberBetween(option, 1, 7))
                break;
            else
            {
				option = clsInputValidation::getNumber("Wrong input!\nWhat do you want to choose? [1 to 7]?");
            }
        }
        return option;
    }
    static void ShowManageUsersMenue()
    {
        while(true)
        {

            system("cls");
            drawScreenHeader("Manage Users Screen");

            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "            Manage Users Menu\n";
            cout << setw(37) << left << "" << "===========================================\n";
            cout << setw(37) << left << "" << "\t[1] List Users.\n";
            cout << setw(37) << left << "" << "\t[2] Add New User.\n";
            cout << setw(37) << left << "" << "\t[3] Delete User.\n";
            cout << setw(37) << left << "" << "\t[4] Update User info.\n";
            cout << setw(37) << left << "" << "\t[5] Update User permissions.\n";
            cout << setw(37) << left << "" << "\t[6] Find User.\n";
            cout << setw(37) << left << "" << "\t[7] Main Menue.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            bool returnToTheMainMene = false;
           returnToTheMainMene= performMainMenuOptions((enManageUsersScreenOptions)ReadManageUsersMenueOption());
           if (returnToTheMainMene)
			   break; 
        }
    }


};

