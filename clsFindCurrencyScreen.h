#pragma once
#include "clsScreen.h";


class clsFindCurrencyScreen : protected clsScreen
{
private :

	enum eFindBy {
		eCountruName = 1, eCurrencyCode = 2
	};

	static short _readSearchType() {
		cout << "Find By [1] Country Name [2] Currency Code ? ";
		short type = clsInputValidate::readIntNumberBetween("Invalid Choice !", 1, 2);
		return type;
	}

	static string _readCountryName() {
		cout << "Enter Country Name : ";
		string str = clsInputValidate::readString();
		return str;
	}

	static string _readCurrencyCode() {
		cout << "Enter Currency Code : ";
		string str = clsInputValidate::readString();
		return str;
	}

	static void _printCurrencyCard(clsCurrency c) {
		cout << "\nCurrency Found :)\n" << endl;

		Utility::tab(40);
		cout << "Country Name   : " << c.CountryName << endl;
		cout << "Currency Code  :" << c.CurrencyCode << endl;
		cout << "Currency Name  :" << c.CurrencyName << endl;
		cout << "Rate           :" << c.ExchangeRate << endl;
		Utility::tab(50);
	}


public:

	static void showFindCurrencyScreen() {
		showScreenHeader("Find Currency Screen");

		short type = _readSearchType();
		
		if (type == eFindBy::eCountruName) {
			string CountryName = _readCountryName();
			clsCurrency c = clsCurrency::findByCountry(CountryName);
			if (!c.isEmpty()) {
				_printCurrencyCard(c);
			}
			else {
				cout << "Currency Not Found !" << endl;
			}
		}
		else if (type == eFindBy::eCurrencyCode) {
			string CurrencyCode = _readCurrencyCode();
			clsCurrency c = clsCurrency::findByCode(CurrencyCode);
			if (!c.isEmpty()) {
				_printCurrencyCard(c);
			}
			else {
				cout << "Currency Not Found !" << endl;
			}
		}
	}

};

