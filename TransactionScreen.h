#pragma once
#include "Screen.h"
#include "ClientsManager.h"
#include "clsInputValidation.h"
#include "DepositeScreen.h"
#include "withdrawlScreen.h"
#include "ShowTotalBalanceScreen.h"
#include "TransferScreen.h"
#include "TransferLogScreen.h"

class TransactionScreen : public Screen
{
public:
	enum class enTransactionScreenOptions { Deposite = 1, Withdraw=2, TotalBalance=3,Transfer=4, TransferLog=5, MainMenue=6 };
private:
	enTransactionScreenOptions option;
public:

	static enTransactionScreenOptions getTransactionScreenOption()
	{
		point:
		int option = clsInputValidation::getNumber("What do you want to choose? 1-6");
		if ((clsInputValidation::isNumberBetween(option, 1, 6)))
		{
			return (enTransactionScreenOptions)option;
		}
		else cout << "Invalid input, enter optino again!" << endl;
		goto point;
	}
	static void clearScreen()
	{
		system("cls");
	}
	static bool performTransactionScreenOption(enTransactionScreenOptions option)
	{
		switch (option)
		{
			case enTransactionScreenOptions::Deposite:
				clearScreen();
				DepositeScreen::showDepositeScreen();
				break;
			case enTransactionScreenOptions::Withdraw:
				clearScreen();
				WithdrawlScreen::showWithdrwalScreen();
				break;
			case enTransactionScreenOptions::TotalBalance:
				clearScreen();
				ShowTotalBalanceScreen::showTotalBalanceScreen();
				break;
			case enTransactionScreenOptions::Transfer:
				clearScreen();
				TransferScreen::showTransferScreen();
				break;
			case enTransactionScreenOptions::TransferLog:
				clearScreen();
				TransferLogScreen::showTransferLogScreen();
				break;
			case enTransactionScreenOptions::MainMenue:
				clearScreen();
				return true;
				break;
		}
		return false; //I first wrote the code without this line and it did not work, why? while the var must stay false?
	}
	static void showTransactionScreen()
	{
		
		bool gotoMain = false;
		while(!gotoMain)
		{
			clearScreen();
			drawScreenHeader("Transaction Screen");
			cout << left << setw(37) << "\t\t\t\t[1] Deposite." << endl;
			cout << left << setw(37) << "\t\t\t\t[2] Withdraw." << endl;
			cout << left << setw(37) << "\t\t\t\t[3] Total Balance." << endl;
			cout << left << setw(37) << "\t\t\t\t[4] Transfer." << endl;
			cout << left << setw(37) << "\t\t\t\t[5] Show Transfer Log." << endl;
			cout << left << setw(37) << "\t\t\t\t[6] Main Menue" << endl;

			gotoMain=performTransactionScreenOption(getTransactionScreenOption());
		}
		
		
		
	}

};

