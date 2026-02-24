#pragma once
#include "Screen.h"
#include "Currency.h"
#include "clsInputValidation.h"
class CurrencyCalculatorScreen :
    protected Screen
{
public: 
    static void showCalculateCurrencyScreen()
    {
        drawScreenHeader("Currency Calculator Screen");
        point:
        string SourceCode = clsInputValidation::readString("Enter the source Currency code:");
        Currency sourceCurrency = Currency::findByCode(SourceCode);
        if (sourceCurrency.isEmptyCurrency())
            goto point;
        point2:
        string DestCode = clsInputValidation::readString("Enter the destination Currency code: ");
        Currency destCurrency = Currency::findByCode(DestCode);
        if (destCurrency.isEmptyCurrency())
            goto point2;
        if (sourceCurrency.getCurrencyCode() == destCurrency.getCurrencyCode())
        {
            cout << "Source Currency code and Dest Currency code cannot be the same!" << endl;
            system("pause");
            return;
        }
        double amount = clsInputValidation::getDouble("Enter the amount to exchange: ");
        double result= Currency::calculateCurrency(sourceCurrency, destCurrency, amount);
        cout << amount <<" "<< sourceCurrency.getCurrencyCode() << "=" << result <<" "<< destCurrency.getCurrencyCode() << endl;
        system("pause");
    }
};

