#pragma once
#include "Person.h"
#include "Permissions.h"
#include <stdint.h>
class User :
    public Person
{
public:

    enum class enUserMode
    {
        EmtpyMode = 0, UpdateMode = 1, AddNewMode = 2
    };
private:
    
    enUserMode mode;
    string userName;
    string salt;
    string password;
    uint32_t permissions;

public:
  

  
    User(string fname, string lname, string phoneNumber, string email, enUserMode Mode, string Username, string Salt, string Password, uint32_t Permissions) : Person(fname, lname, phoneNumber, email), mode(Mode), userName(Username),salt(Salt), password(Password), permissions(Permissions)
    {

    }
    void setUsername(string u)
    {
        userName = u;
    }
    void setPassword(string p)
    {
        password = p;
    }
    void setPersmissions(uint32_t p)
    {
        permissions = p;
    }
    void setMode(enUserMode Mode)
    {
        mode = Mode;
    }

    void setSalt(string Salt)
    {
        salt = Salt;
    }

    string getUsername() const
    {
        return userName;
    }
    string getPassword() const
    {
        return password;
    }
    uint32_t getPermissions() const
    {
        return permissions;
    }
    enUserMode getMode() const
    {
        return mode;
    }
    string getSalt() const
    {
        return salt;
    }
    bool isEmptyUser() const
    {
        return (mode == enUserMode::EmtpyMode);
    }
    static User returnEmptyUser()
    {
        User u("", "", "", "", enUserMode::EmtpyMode, "","", "", 0);
        return u;
    }
    bool isEmptyUser()
    {
        return (mode == enUserMode::EmtpyMode);
    }
  
    void printUser()
    {
        cout << "User Information:" << endl;
        cout << "---------------------------------" << endl;
        cout << "Full Name      : " << getFullName() << endl;
        cout << "Phone Number   : " << getPhoneNumber() << endl;
        cout << "Email          : " << getEmail() << endl;
        cout << "Username       : " <<getUsername() << endl;
        cout << "Password       : " << getPassword() << endl;
        cout << "Permissions    : " << getPermissions() << endl;
        cout << "---------------------------------" << endl;

    }

};

