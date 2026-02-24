#pragma once
using namespace std;
#include <iostream>
class ChangeOutputColor
{

public:
    static string setRed(string inputToMakeRed)
    {
        return ("\033[31m" + inputToMakeRed + "\033[0m");
    }

    static string setGreen(string inputToMakeRed)
    {
        return ("\033[32m" + inputToMakeRed + "\033[0m");

    }

    static string setBlue(string inputToMakeRed)
    {
        return ("\033[33m" + inputToMakeRed + "\033[0m");

    }

    static string resetColor(string inputToMakeRed)
    {
        return ("\033[31m" + inputToMakeRed + "\033[0m");

    }





};

