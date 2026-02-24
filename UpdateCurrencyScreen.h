#pragma once
#include "Screen.h"
#include "Currency.h"
#include "clsInputValidation.h"
#include "ChangeOutputColor.h"
#include "FindCurrencyScreen.h"
class UpdateCurrencyScreen :
    protected Screen
{
public:
    static void showUpdateCurrencyScreen()
    {
		Currency currency = Currency::returnEmpatyCurrency();
		drawScreenHeader("Update Currency Exchange Rate");
		while(true)
		{
			string code = clsInputValidation::readString("Enter the currency code to update its exchange rate:");
			 currency = Currency::findByCode(code);
			if (!(currency.getMode() == Currency::Mode::EmptyMode))
			{
				break;
			}
			cout << ChangeOutputColor::setRed("No Currency found witht this code") << endl;
		}
		currency.printCurrency();
		float newRate = clsInputValidation::getFloat("Enter the new Rate: ");
		currency.setExchangeRateToUSD(newRate);
		Currency::replaceCurrencyObject(currency);
		cout << ChangeOutputColor::setGreen("Currency exchange rate updated successfully!") << endl;
		currency.printCurrency();
		system("pause");
    }
};

