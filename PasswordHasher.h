#pragma once

#include <string>
#include <random>
#include <sstream>
#include <iomanip>
#include <functional>

using namespace std;

class PasswordHasher
{
public:

    static string generateSalt(size_t length=16) // why did i wrote the length as a paramter?
    {
        static const char charset[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
        random_device rd;
        mt19937 generator(rd());
        uniform_int_distribution<> distribution(0, sizeof(charset) - 2); //or i can use a string and use length funciton without -2

        string salt;
        salt.reserve(length);
        for (int i = 0; i < length; i++)
        {
            salt += charset[distribution(generator)];
        }
       
        return salt;

    }

    static string hashPassword(const string & password, const string & salt)
    {
        hash<string> hasher;
		size_t hashedValue = hasher(password + salt);
        stringstream ss;
        ss << hex << hashedValue; // convert to hexadecimal string
		return ss.str();
    }
    static bool varifyPassword(const string & inputPassword, const string & storedHash, const string & salt)
    {
        string inputHash = hashPassword(inputPassword, salt);
        return inputHash == storedHash;
	}
    
};
