#pragma once
#include <iostream>
using namespace std;
class clsInputValidation
{
	
public:
	static float getFloat(string message)
	{
		cout << message << endl;
		float f;
		cin >> f;
		if (cin.fail())
		{
			cin.clear(); // Clear the error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input
			cout << "Invalid input" << endl;
			return -1;
		}
		else
		return f;
	}
	static double getDouble(string message)
	{
		cout << message << endl;
		double f;
		cin >> f;
		if (cin.fail())
		{
			cin.clear(); // Clear the error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input
			cout << "Invalid input" << endl;
			return -1;
		}
		else
			return f;
	}
	static int getNumber(string message)
	{
		
		cout << message << endl;
		int n=-1;
		cin >> n;
		if (cin.fail())
		{
			cin.clear(); // Clear the error state
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input
			cout << "Invalid input" << endl;
			return -1;
		}
		else
		return n;
	}
	static bool isNumberBetween(float Number, float Min, float Max)
	{
		if (Number < Min || Number > Max)
			return false;
		return true;
	}
	static bool getConfirmation(string message)
	{
		cout << message << endl;
		char answer;
		cin >> answer;
		if (answer != 'y' && answer != 'n' && answer!='Y' && answer!='N')
		{
			throw std::invalid_argument("Invalid input. Please enter 'y' or 'n'.");
		}
		return (answer == 'y' || answer == 'Y');
		
	}

	static string readString(string message)
	{
		cout << message << endl;
		string str;
		cin >> str;
		return str;
	}

	static double readDouble(string message)
	{
		cout << message << endl;
		double d;
		cin >> d;
		return d;
	}
	static char readChar(string message)
	{
		cout << message << endl;
		char c;
		cin >> c;
		return c;
	}

};

