#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsCurrency.h";
#include "Utility.h";

using namespace std;


class clsCurrenciesListScreen : protected clsScreen
{
private:

	static clsCurrency _convertLineToCurrency(string line,string del ="#//#") {
		vector<string> v = clsString::Split(line, del);
		return clsCurrency(v[0], v[1], v[2], stof(v[3]),(clsCurrency::eMode::eUpdateMode));
	}

	static void _printCurrencyLine(clsCurrency c) {

		cout << "\t" << left << setw(35) << "| " + c.CountryName;
		cout << "\t" << left << setw(10) << "| " + c.CurrencyCode;
		cout << "\t" << left << setw(35) << "| " + c.CurrencyName;
		cout << "\t" << left << setw(15) << "| " + to_string(c.ExchangeRate) + "\n";

	}

public:

	static void showCurrenciesListScreen() {

		vector<clsCurrency> v = clsCurrency::getCurrenciesList();

		string subTitle = "Currencies (" + to_string(v.size()) + ") s";
		showScreenHeader("Currenceis List Screen", subTitle);

		cout << "\n\t"; Utility::tab(110);
		cout <<"\t"<< left << setw(35) << "| Country";
		cout <<"\t"<< left << setw(10) << "| Code";
		cout <<"\t"<< left << setw(35) << "| Name";
		cout <<"\t"<< left << setw(15) << "| Rate ($)";
		cout << "\n\t"; Utility::tab(110);

		for (clsCurrency& temp : v) {
			_printCurrencyLine(temp);
		}

		cout << "\n\t"; Utility::tab(110);

	}

};

