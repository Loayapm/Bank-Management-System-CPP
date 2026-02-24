#pragma once
using namespace std;
#include <iostream>
#include <iomanip>
#include "User.h"
#include "Session.h"
#include "ChangeOutputColor.h"
#include "DateTime.h"
class Screen
{
protected: 
	static void drawScreenHeader(string Title, string subTitle = "")
	{
		cout << left << setw(37) << "\t\t\t\t-----------------------------------------------------" << endl;
		cout << left << setw(37) << "\t\t"<<Title << endl;
		cout << left << setw(37) << "\t\t"<<subTitle << endl;
		cout << left << setw(37) << "\t\t\t\t-----------------------------------------------------" << endl;
		User u = Session::returnCurrentUser();
		cout << left << setw(37) << "\t" <<"Date And Time:"<< DateTime::getCurrentDateTime() << endl;
		cout << left << setw(37) << "\t" << "User: " << u.getFullName() << endl;
		cout << left << setw(37) << "\t\t\t\t-----------------------------------------------------" << endl;

	
	}
};

