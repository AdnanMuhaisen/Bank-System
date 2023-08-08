#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsCurrenciesListScreen.h";
#include "clsFindCurrencyScreen.h";
#include "clsUpdateCurrencyExchangeRateScreen.h";
#include "clsCurrencyCalculatorScreen.h";


using namespace std;

class clsCurrencyExchangeMainScreen : protected clsScreen
{

private:

	enum eCurrencyOperations {
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5
	};

	static void goBackToCurrencyExchangeMenue() {
		cout << "Enter Any Key To Go Back To Currency Menue..." << endl;
		system("Pause");
		system("cls");
		showCurrencyExchangeMainScreen();
	}

	static void _showListCurrenciesScreen() {
		clsCurrenciesListScreen::showCurrenciesListScreen();
	}

	static void _showFindCurrencyScreen() {
		clsFindCurrencyScreen::showFindCurrencyScreen();
	}

	static void _showUpdateRateScreen() {
		clsUpdateCurrencyExchangeRateScreen::showUpdateCurrencyExchangeRateScreen();
	}

	static void _showCurrencyCalculatorScreen() {
		clsCurrencyCalculatorScreen::showCurrencyCalculatorScreen();
	}

	static void _performCurrencyChangeOperation(short choice) {
		
		system("cls");
		switch (choice) {
		case eCurrencyOperations::eListCurrencies:
			_showListCurrenciesScreen();
			goBackToCurrencyExchangeMenue();
			break;

		case eCurrencyOperations::eFindCurrency:
			_showFindCurrencyScreen();
			goBackToCurrencyExchangeMenue();
			break;

		case eCurrencyOperations::eUpdateRate:
			_showUpdateRateScreen();
			goBackToCurrencyExchangeMenue();
			break;

		case eCurrencyOperations::eCurrencyCalculator:
			_showCurrencyCalculatorScreen();
			goBackToCurrencyExchangeMenue();
			break;

		case eCurrencyOperations::eMainMenue:
			//the system handle this case ...
			break;
		}
	}

public:

	static void showCurrencyExchangeMainScreen() {

		showScreenHeader("Currency Exchange Main Screen");

		cout << "\n\t\t\t"; Utility::tab(50);
		cout << "\n\t\t\t\t\tCurrency Exchange Menue\n\n";
		cout << "\t\t\t"; Utility::tab(50);

		cout << "\t\t\t\t[1] List Currencies\n";
		cout << "\t\t\t\t[2] Find Currency\n";
		cout << "\t\t\t\t[3] Update Rate\n";
		cout << "\t\t\t\t[4] Currency Calculator\n";
		cout << "\t\t\t\t[5] Main Menue\n";
		cout << "\t\t\t"; Utility::tab(50);

		
		cout << "\t\t\tChoose What Do You Want To Do [1,5] ? ";
		_performCurrencyChangeOperation(clsInputValidate::readIntNumberBetween("Invalid Choice , Try Again !", 1, 5));

	}
};

