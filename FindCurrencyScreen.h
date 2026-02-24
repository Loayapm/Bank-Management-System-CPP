#pragma once
#include "Screen.h"
#include "Currency.h"
#include "clsInputValidation.h"
#include "ChangeOutputColor.h"
class FindCurrencyScreen :
    protected Screen
{
    public:
    static void showFindCurrencyScreen()
    {
        drawScreenHeader("Find Currency Screen");
		int option = clsInputValidation::getNumber("Do You Want To Find Currency By Country Or By Code? 1-By Country, 2-By Code");
        while (true)
        {
			if (clsInputValidation::isNumberBetween(option, 1, 2))
                break;
            else option = clsInputValidation::getNumber("Wrong input! Do You Want To Find Currency By Country Or By Code? 1-By Country, 2-By Code");
        }
		Currency c = Currency::returnEmpatyCurrency();
        if (option == 1)
        {
            string country = clsInputValidation::readString("Enter The Country Name To Find Its Currency:");
             c = Currency::findByCountry(country);

        
        }
        else
        {
            string code = clsInputValidation::readString("Enter The Currency Code To Find Its Currency:");
             c = Currency::findByCode(code);
			
		}

        if (c.getMode() == Currency::Mode::EmptyMode)
        {
            cout << ChangeOutputColor::setRed( "No currency found for the specified country.") << endl;
			system("pause");
        }
        else
        {
            cout <<ChangeOutputColor::setGreen( "Currency found:") << endl;
			cout << string(50, '-') << endl;
            cout << "Country             : " << c.getCountry() << endl;
            cout << "Currency Code       : " << c.getCurrencyCode() << endl;
            cout << "Currency Name       : " << c.getCurrencyName() << endl;
            cout << "Exchange Rate to USD: " << c.getExchangeRateToUSD() << endl;
			cout << string(50, '-') << endl;
			system("pause");
        }
	}
};

