#pragma once
#include "Screen.h"
#include "clsInputValidation.h"
#include "ListCurrenciesScreen.h"
#include "FindCurrencyScreen.h"
#include "UpdateCurrencyScreen.h"
#include "CurrencyCalculatorScreen.h"
class CurrencyExchangeScreen :
    private Screen
{
public:
	enum class enCurrencyExchangeOptions
	{
		listCurrencies = 1, findCurrency = 2, updateRate = 3, currencyCalculator = 4, mainMenu = 5
	};

	static bool performCurrencyExchangeOptions(enCurrencyExchangeOptions option)
	{
		switch (option)
		{
			case enCurrencyExchangeOptions::listCurrencies:
				clearScreen();
				ListCurrenciesScreen::showListCurrenciesScreen();
				break;
			case enCurrencyExchangeOptions::findCurrency:
				clearScreen();
				FindCurrencyScreen::showFindCurrencyScreen();
				break;
			case enCurrencyExchangeOptions::updateRate:
				clearScreen();
				UpdateCurrencyScreen::showUpdateCurrencyScreen();
				break;
			case enCurrencyExchangeOptions::currencyCalculator:
				clearScreen();
				CurrencyCalculatorScreen::showCalculateCurrencyScreen();
				break;
			case enCurrencyExchangeOptions::mainMenu:
				return true;
				break;
		}
		return false;
	}
	static enCurrencyExchangeOptions getCurrencyExchangeOption()
	{
		int option = clsInputValidation::getNumber("What do you want to choose? 1-5");
		while (true)
		{
			if (clsInputValidation::isNumberBetween(option, 1, 5))
				break;
			else option = clsInputValidation::getNumber("Wrong input!");
		}
		enCurrencyExchangeOptions enOption= static_cast<enCurrencyExchangeOptions>(option);
		return enOption;
	}
    static void showCurrencyExchangeScreen()
    {
        drawScreenHeader("Currency Exchange Screen");
		while (true)
		{

			clearScreen();
			drawScreenHeader("Main Screen");

			cout << left << setw(37) << "\t\t\t\t[1] List Currencies." << endl;
			cout << left << setw(37) << "\t\t\t\t[2] Find Currency." << endl;
			cout << left << setw(37) << "\t\t\t\t[3] Update Rate." << endl;
			cout << left << setw(37) << "\t\t\t\t[4] Currency Calculator." << endl;
			cout << left << setw(37) << "\t\t\t\t[5] Main Menu." << endl;
			

			if (performCurrencyExchangeOptions(getCurrencyExchangeOption()))
				break;;
		}
	}
	static void clearScreen()
	{
		system("cls");
	}
};

