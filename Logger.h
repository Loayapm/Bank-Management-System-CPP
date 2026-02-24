#pragma once
#include "DateTime.h"
#include "User.h"
#include <fstream>
#include <vector>
#include "Log.h"
#include <iomanip>
class Logger
{
	private:
		static vector <Log> LogVector;
public:
	static void logUser(User currentUser)
	{
		string dateTime = DateTime::getCurrentDateTime();
		ofstream log("D:\\Log.txt", ios::app);
		log << dateTime <<" | "<< currentUser.getFullName() << " | " << currentUser.getUsername() << " | " << currentUser.getPermissions() << endl;
	}
	static void loadLogsToVector()
	{
		LogVector.clear();
		ifstream logFile("D:\\Log.txt");
		string line;
		while (getline(logFile, line))
		{
			Log log = SplitString(line," | ");
			LogVector.push_back(log);
		}
	}
	static void printLogs()
	{
		cout << "---------------------------------------------------------------------------------" << endl;

		cout << left << "| " << setw(20) << "Login Date And Time"
			<< left << "| " << setw(20) << "User Full Name"
			<< left << "| " << setw(20) << "Username"
			<< left << "| " << setw(20) << "Permissions" << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
		for (Log l : LogVector)
		{
			cout << left <<"| "<< setw(20) << l.getDateTime()
				<< left << "| " << setw(20) << l.getFullName()
				<< left << "| " << setw(20) << l.getUserName()
				<< left << "| " << setw(20) << l.getPermissions() << endl;
		}
		cout << "---------------------------------------------------------------------------------" << endl;

	
	}
	static void printLogs(string username)
	{
		cout << "---------------------------------------------------------------------------------" << endl;

		cout << left << "| " << setw(20) << "Login Date And Time"
			<< left << "| " << setw(20) << "User Full Name"
			<< left << "| " << setw(20) << "Username"
			<< left << "| " << setw(20) << "Permissions" << endl;
		cout << "---------------------------------------------------------------------------------" << endl;
		int records = 0;
		for (Log l : LogVector)
		{
			if(l.getUserName()==username)
			{

				cout << left << "| " << setw(20) << l.getDateTime()
					<< left << "| " << setw(20) << l.getFullName()
					<< left << "| " << setw(20) << l.getUserName()
					<< left << "| " << setw(20) << l.getPermissions() << endl;
				records++;
			}

		}
		if (records == 0)
			cout << "There are not records to show" << endl;
		cout << "---------------------------------------------------------------------------------" << endl;


	}
	static Log SplitString(const string & line, const string & delimiter)
	{
		vector<string> tokens;
		size_t start = 0;
		size_t end;

		while ((end = line.find(delimiter, start)) != string::npos)
		{
			tokens.push_back(line.substr(start, end - start));
			start = end + delimiter.length();
		}

		// last token
		tokens.push_back(line.substr(start));

		Log log(
			tokens[0],
			tokens[1],
			tokens[2],
			tokens[3]
		);
		return log;
	}
};

