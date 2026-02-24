#pragma once
#include "Screen.h"
#include "Currency.h"
class ListCurrenciesScreen :
    protected Screen
{
public:
    static void showListCurrenciesScreen()
    {
        drawScreenHeader("List Currencies Screen");
		Currency::listCurrencies();
	}
};

