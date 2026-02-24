#pragma once
#include "Screen.h"
#include "UsersManager.h"
#include "clsInputValidation.h"
#include "ChangeOutputColor.h"
#include "User.h"
#include "Session.h"
class DeleteUserScreen :
    protected Screen
{
public:
    static void ShowDeleteUserScreen()
    {
        string username = clsInputValidation::readString("Enter the user name for the user you want to delete: ");
        if (!(UsersManager::isUserExists(username)))
        {
            cout << ChangeOutputColor::setRed("No User Exist with this username!") << endl;
            system("pause");
            return;
        }
        User userToDelete = UsersManager::findUser(username);
        
        if (userToDelete.getUsername() == Session::returnCurrentUser().getUsername())
        {
            cout << ChangeOutputColor::setRed("You cannot Delete Your Record!") << endl;
            system("pause");
            return;
        }
        userToDelete.printUser();
        char wannaDelete = clsInputValidation::readChar("Do you want to delete this user? y/n");
        if (wannaDelete == 'y' || wannaDelete == 'Y')
        {
            if (UsersManager::deleteUser(userToDelete))
            {
                cout << ChangeOutputColor::setGreen("User Delete Successfully!") << endl;
                
                system("pause");
            }
            else
            {
                cout <<ChangeOutputColor::setRed( "Cannot Delete Admin User!") << endl;
                
                system("pause");
            }
        }
    }
};

