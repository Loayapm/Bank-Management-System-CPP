#pragma once
#include "Screen.h"
#include "clsInputValidation.h"
#include "User.h"
#include "UsersManager.h"
#include "ChangeOutputColor.h"
class UpdateUserScreen :
    protected Screen
{
public:
    static void ShowUpdateUserScreen()
    {
        string username = clsInputValidation::readString("Enter the Username for the user you want to update: ");
        if (!(UsersManager::isUserExists(username)))
        {
            cout << ChangeOutputColor::setRed("No User found with this username!")<<endl;
            system("pause");
            return;
        }
        User userToUpdate = UsersManager::findUser(username);
        userToUpdate.printUser();
        UsersManager::updateUser(userToUpdate);
        cout << ChangeOutputColor::setGreen("User Updated Successfully")<<endl;
     
        User updatedUser = UsersManager::findUser(username);
        updatedUser.printUser();
        system("pause");
        
    }
};

