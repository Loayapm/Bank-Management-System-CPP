#pragma once
using namespace std;
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <algorithm>
class Currency
{
	public:
		enum class Mode
		{
			EmptyMode=0, UpdateMode=1
		};

private :

	Mode mode;
	string country;
	string currencyCode;
	string currencyName;
	float exchangeRateToUSD;
	static vector <Currency> currenciesList;


public:
	//getters
	string getCountry() const
	{
		return country;
	}
	string getCurrencyCode() const
	{
		return currencyCode;
	}
	string getCurrencyName() const
	{
		return currencyName;
	}
	float getExchangeRateToUSD() const
	{
		return exchangeRateToUSD;
	}
	Mode getMode() const
	{
		return mode;
	}
	//setter only for the rate
	void setExchangeRateToUSD(float newRate)
	{
		exchangeRateToUSD = newRate;
	}


	Currency(Mode mode, string country, string currencyCode, string currencyName, float exchangeRateToUSD) : mode(mode), country(country), currencyCode(currencyCode), currencyName(currencyName), exchangeRateToUSD(exchangeRateToUSD)
	{}
	static Currency SplitString(const string & line, const string & delimiter)
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

		Currency currency(
			Currency::Mode::UpdateMode,
			tokens[0],
			tokens[1],
			tokens[2],
			stof(tokens[3])
			
		);
		return currency;
	}
	static void fillVectorFromFile()
	{
		currenciesList.clear();
		ifstream file("D:\\Currencies.txt");
		if (!(file.is_open()))
		{
			cout << "Error in opening file!" << endl;
			return;
		}
		string line;
		while (getline(file, line))
		{
			Currency c = SplitString(line, "#//#");
			currenciesList.push_back(c);
		}
	}
	static void saveVectorToFile()
	{
		ofstream file("D:\\Currencies.txt");
		if (!(file.is_open()))
		{
			cout << "Error in opening file!" << endl;
			system("pause");
			return;
		}
		for (const auto& currency : currenciesList)
		{
			file << currency.getCountry() << "#//#" << currency.getCurrencyCode() << "#//#" << currency.getCurrencyName() << "#//#" << currency.getExchangeRateToUSD() << endl;
		}
	}
	static Currency returnEmpatyCurrency()
	{
		Currency emptyCurrency(Currency::Mode::EmptyMode, "", "", "", 0.0f);
		return emptyCurrency;
	}

	static Currency findByCountry(string country)
	{
		fillVectorFromFile();
		country = toUpper(country);
		for (const auto& currency : currenciesList)
		{
			if (toUpper(currency.getCountry()) == country)
			{
				return currency;
			}
		}
		return returnEmpatyCurrency();
		
	}
	static string toUpper(string s)
	{
		transform(s.begin(), s.end(), s.begin(),
			[](unsigned char c)
			{
				return toupper(c);
			});
		return s;
	}
	static Currency findByCode(string code)
	{
		fillVectorFromFile();
		code = toUpper(code);
		for (const auto& currency : currenciesList)
		{
			if (toUpper(currency.getCurrencyCode()) == code)
			{
				return currency;
			}
		}
		return returnEmpatyCurrency();
	}
	static bool isCurrencyExist(string code)
	{
		for (const auto& currency : currenciesList)
		{
			if (currency.getCurrencyCode() == code)
			{
				return true;
			}
		}
		return false;
	}
	static void replaceCurrencyObject(Currency currency)
	{
		for (Currency &c : currenciesList)
		{
			if (c.getCurrencyCode() == currency.getCurrencyCode())
			{
				c.setExchangeRateToUSD(currency.getExchangeRateToUSD());
			
				break;
			}
		}
		saveVectorToFile();
		fillVectorFromFile();
	}
	static void listCurrencies()
	{
		fillVectorFromFile();
		cout << fixed << setprecision(4);
		cout << left <<" |"<< setw(30) << "Country"
			<< left << " |" << setw(20) << "Currency Code"
			<< left << " |" << setw(40) << "Currency Name"
			<< left << " |" << setw(20) << "Exchange Rate to USD" << endl;

		cout << string(130, '-') << endl;
		for (const auto& currency : currenciesList)
		{
			cout << left <<" |"<< setw(30) << currency.getCountry()
				<< left << " |" << setw(20) << currency.getCurrencyCode()
				<< left << " |" << setw(40) << currency.getCurrencyName()
				<< left << " |" << setw(20) << currency.getExchangeRateToUSD() << endl;
		}
		cout << string(130, '-') << endl;
		system("pause");
	}
	void printCurrency() const
	{
		cout << string(60,'-') << endl;
		cout << "Country              : " << country<< endl;
		cout << "Currency Code        : " << currencyCode << endl;
		cout << "Currency Name        : " << currencyName << endl;
		cout << "Exchange Rate to USD : " << exchangeRateToUSD << endl;
		cout << string(60,'-') << endl;
	}

	static double convertToDollar(float amount, Currency c)
	{
		double rate = c.getExchangeRateToUSD();
		return amount / rate;
	}
	static double convertFromDollar(float amount, Currency c)
	{
		double rate = c.getExchangeRateToUSD();
		return amount * rate;
	}
	static double calculateCurrency(Currency fromCurrency,Currency toCurrency,float amount)
	{
		
		if (fromCurrency.getCurrencyCode() == "USD")
		{
			return convertFromDollar(amount, toCurrency);
		}
		else if (toCurrency.getCurrencyCode() == "USD")
		{
			return convertToDollar(amount, fromCurrency);
		}
		else
		{
			double fromTodollar = convertToDollar(amount, fromCurrency);
			return (convertFromDollar(fromTodollar, toCurrency));
		}
	}
	bool isEmptyCurrency() const
	{
		return mode == Mode::EmptyMode;
	}

};

