#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsCurrency.h";


using namespace std;

class clsUpdateCurrencyExchangeRateScreen : protected clsScreen
{

private:

	static void _printCurrencyCard(clsCurrency c) {
		cout << "\nCurrency Card :)\n" << endl;

		Utility::tab(50);
		cout << "Country Name   : " << c.CountryName << endl;
		cout << "Currency Code  :" << c.CurrencyCode << endl;
		cout << "Currency Name  :" << c.CurrencyName << endl;
		cout << "Rate           :" << c.ExchangeRate << endl;
		Utility::tab(50);
	}


public:
	static void showUpdateCurrencyExchangeRateScreen() {

		showScreenHeader("Update Currency Rate Screen");

		cout << "\nEnter Currency Code : ";
		string code = clsInputValidate::readString();
		clsCurrency target = clsCurrency::findByCode(code);

		while (target.isEmpty()) {
			cout << "Invalid Code Try Again!" << endl;
			code = clsInputValidate::readString();
			target = clsCurrency::findByCode(code);
		}

		_printCurrencyCard(target);
		if (clsInputValidate::readDecision("Are You Sure You Want To Update This Currency ?")) {
			cout << "Enter The New Rate Please : ";
			float updatedRate = (float)clsInputValidate::readDoubleNumber("Invalid Number !");
			target.updateExchangeRate(updatedRate);
			cout << "Updated Succesfully :) \n" << endl;
			_printCurrencyCard(target);
		}
		else {
			cout << "Operation Canceled !" << endl;
		}

	}

};

