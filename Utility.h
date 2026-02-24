#pragma once
#include <iostream>
using namespace std;


class Utility
{
    public:
	static string numberToWords(int n)
	{
        string belowTwenty[] = {
    "", "one", "two", "three", "four", "five", "six", "seven",
    "eight", "nine", "ten", "eleven", "twelve", "thirteen",
    "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
        };

        string tens[] = {
            "", "", "twenty", "thirty", "forty", "fifty",
            "sixty", "seventy", "eighty", "ninety"
        };

        if (n == 0)
            return "";

        if (n < 20)
            return belowTwenty[n];

        if (n < 100)
            return tens[n / 10] + (n % 10 ? " " + numberToWords(n % 10) : "");

        if (n < 1000)
            return numberToWords(n / 100) + " hundred" +
            (n % 100 ? " " + numberToWords(n % 100) : "");

        if (n < 1000000)
            return numberToWords(n / 1000) + " thousand" +
            (n % 1000 ? " " + numberToWords(n % 1000) : "");

        if (n < 1000000000)
            return numberToWords(n / 1000000) + " million" +
            (n % 1000000 ? " " + numberToWords(n % 1000000) : "");

        return numberToWords(n / 1000000000) + " billion" +
            (n % 1000000000 ? " " + numberToWords(n % 1000000000) : "");
    }

   
};

