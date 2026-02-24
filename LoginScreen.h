#pragma once
#include "Screen.h"
#include "clsInputValidation.h"
#include "User.h"
#include "UsersManager.h"
#include "Session.h"
#include "ChangeOutputColor.h"

class LoginScreen :
    protected Screen
{
public:
    static void showLoginScreen()
    {
        drawScreenHeader("Login Screen");
        Session::Logout(); //to make sure that the global object is empty and isloggedin is false
        User u = User::returnEmptyUser();
        int counter = 0;
        while (counter<3)
        {
            string username = clsInputValidation::readString("Enter Username: ");
            string password = clsInputValidation::readString("Enter Password: ");
           // User user = UsersManager::findUser(username);
           // string salt = user.getSalt();
             u = UsersManager::findUserWithUsernameAndPassword(username, password);
            if (u.isEmptyUser())
            {
                counter++;
                cout << ChangeOutputColor::setRed("Invalid login info!") << endl;
              /*  string output = "You Still Have " + (3 - counter);
                cout << ChangeOutputColor::setRed(output) << endl;*/
                cout << "You Still Have " << ChangeOutputColor::setRed(to_string(3 - counter)) << " Attempts."<< endl;
                if (counter == 3) break;

            }
            else
            {
                Session::Login(u);
                return;
            }
        }
        cout << ChangeOutputColor::setRed("You Are locked out of the system!") << endl;
       return;
       
    }
};

