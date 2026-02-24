#pragma once
#include "DateTime.h"
#include <fstream>
#include <iomanip>
#include "TransferLog.h"
#include <vector>

using namespace std;

class TransactionLogger
{
private:
	static vector <TransferLog> transferLogsVector;
public:
	static void logTransfer(string sourceAcc, string destAcc, double TAmount, double fromBalanceAfter, double toBalanceAfter, string user)
	{
		
		ofstream TransfersLog("D:\\TransferLog.txt", ios::app);
		if (!(TransfersLog.is_open()))
		{
			cerr << "Error opening file for logging transfer." << endl;
			system("pause");
			return;
		}
		
		string dt = DateTime::getCurrentDateTime();
		string delimer = "#//#";
		TransfersLog << dt << delimer
			<< sourceAcc << delimer
			<< destAcc << delimer
			<< to_string(TAmount) << delimer
			<< to_string(fromBalanceAfter) << delimer
			<< to_string(toBalanceAfter) << delimer
			<< user << endl;
	}
	static void loadTransferLogsFromFile()
	{
		transferLogsVector.clear();
		ifstream tLogs("D:\\TransferLog.txt");
		string line;
		while (getline(tLogs, line))
		{
			transferLogsVector.push_back(SplitString(line, "#//#"));
		}
	}
	static TransferLog SplitString(const string & line, const string & delimiter)
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
		
		TransferLog log(
			tokens[0],
			tokens[1],
			tokens[2],
			stod(tokens[3]),
			stod(tokens[4]),
			stod(tokens[5]),
			tokens[6]
		);
		return log;
	}
	static void loadTransferLogsToFile()
	{
		ofstream tLogs("D:\\TransferLog.txt", ios::trunc);
		for (const auto& log : transferLogsVector)
		{
			tLogs << log.getDateTime() << "#//#"
				<< log.getSourceAcc() << "#//#"
				<< log.getDestAcc() << "#//#"
				<< to_string(log.getTAmount()) << "#//#"
				<< to_string(log.getSourceRAmount()) << "#//#"
				<< to_string(log.getDestRAmount()) << "#//#"
				<<log.getUser() << endl;
		}
	}
	static void printTransferLogs()
	{
		loadTransferLogsFromFile();
		cout <<"---------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		cout << left << " |" << setw(20) << "DateTime" << " |" << setw(15) << "Source Account" << " |" << setw(20) << "Destination Account" << " |" << setw(15) << "Transfer Amount" << " |" << setw(25) << "Source Remaining Amount" << " |" << setw(29) << "Destination Remaining Amount" << " |" << setw(15) << "User" << endl;
		cout <<"---------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
		for (const auto& log : transferLogsVector)
		{
			cout << left << " |"
				<< setw(20) << log.getDateTime() 
				<< " |" << setw(15) << log.getSourceAcc() 
				<< " |" << setw(20) << log.getDestAcc() 
				<< " |" << setw(15) << log.getTAmount() 
				<< " |" << setw(25) << log.getSourceRAmount() 
				<< " |" << setw(29) << log.getDestRAmount() 
				<< " |" << setw(15) << log.getUser() << endl;
		}
		cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
		system("pause");
	}
};