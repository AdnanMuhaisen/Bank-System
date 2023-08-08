#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsCurrency.h";
#include "clsInputValidate.h";


using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{

private:

	static clsCurrency _readCurrencyInfo(short index) {
		cout << "Enter Currency" << index << " Code : ";
		string code = clsInputValidate::readString();
		clsCurrency target = clsCurrency::findByCode(code);

		while (target.isEmpty()) {
			cout << "Currency Not Fount Enter Another Currency Code : ";
			code = clsInputValidate::readString();
			target = clsCurrency::findByCode(code);
		}

		return target;
	}

	static void _printCurrencyCard(clsCurrency c) {
		cout << "\nCurrency Card :)\n" << endl;

		Utility::tab(50);
		cout << "Country Name   : " << c.CountryName << endl;
		cout << "Currency Code  :" << c.CurrencyCode << endl;
		cout << "Currency Name  :" << c.CurrencyName << endl;
		cout << "Rate           :" << c.ExchangeRate << endl;
		Utility::tab(50);
	}

	static float _readAmountToConvert() {
		float temp;
		cout << "Enter Amount To Convert : ";
		temp = (float)clsInputValidate::readDoubleNumber("Invalid Number !");
		return temp;
	}


public:
	static void showCurrencyCalculatorScreen() {
		
		do {
			system("cls");
			showScreenHeader("Currency Calculator Screen");

			clsCurrency convertFrom = _readCurrencyInfo(1);
			clsCurrency convertTo = _readCurrencyInfo(2);

			cout << "Convert From :" << endl;
			_printCurrencyCard(convertFrom);

			float amount = _readAmountToConvert();

			cout << "Convert To :" << endl;
			_printCurrencyCard(convertTo);

			cout << amount << " " << convertFrom.CurrencyCode << " = " <<
				convertFrom.calculateAmountInAnyCurrency(convertTo, amount) << " " << convertTo.CurrencyCode << endl;

		} while (clsInputValidate::readDecision("Do You Want To Perform Another Calculation ?"));
	}
};

