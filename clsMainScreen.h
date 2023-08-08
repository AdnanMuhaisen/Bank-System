#pragma once

#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsClientsListScreen.h";
#include "clsAddnewClientScreen.h";
#include "clsDeleteClientScreen.h";
#include "clsUpdateClientScreen.h";
#include "clsFindClientScreen.h";
#include "clsTransactionsScreen.h";
#include "clsManageUsersScreen.h";
#include "clsLoginRegisterListScreen.h";
#include "clsCurrencyExchangeMainScreen.h";
#include "Global.h";

using namespace std;

class clsMainScreen : protected clsScreen
{

private:

	enum eMainMenueOptions {
		eShowClientsList = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4,
		eFindClient = 5, eTransactions = 6, eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eLogout = 10
	};

	static short _readMainMenueOption() {
		cout << "\t\t\tChoose What Do You Want To Do ? [1,8] ";
		short choice = clsInputValidate::readIntNumberBetween("Invalid Number , Try Again !", 1, 10); cout << endl;
		return choice;
	}

	static void _goBackToMainMenue() {
		cout << "\nPrees Any Key To Go Back To Main Menue .. \n" << endl;

		system("pause");
		system("cls");
		showMainMenueOptions();
	}

	static void _showClientsListScreen(){
		clsClientsListScreen::showClientsListScreen();
	}

	static void _showAddNewClentScreen() {
		clsAddnewClientScreen::showAddNewClientScreen();
	}

	static void _showDeleteClientScreen() {
		clsDeleteClientScreen::showDeleteClientScreen();
	}

	static void _showUpdateClient() {
		clsUpdateClientScreen::showUpdateClientScreen();
	}

	static void _showFindClient() {
		clsFindClientScreen::showFindClientScreen();
	}

	static void _showTransactionsScreen() {
		clsTransactionsScreen::showTransactionsMenue();
	}

	static void _showManageUsersScreen() {
		clsManageUsersScreen::showManageUsersScreen();
	}

	static void _showLoginRegisterScreen() {
		clsLoginRegisterScreen::showLoginRegisterListScreen();
	}

	static void _showCurrencyExchangeScreen() {
		clsCurrencyExchangeMainScreen::showCurrencyExchangeMainScreen();
	}

	static void _logout() {
		currentUser = clsUser::find("");
		//then the system will end the flow of operation and exit;
	}

	static void _performMainMenueOption(eMainMenueOptions option) {

		switch (option) {

		case eMainMenueOptions::eShowClientsList:
			system("cls");
			_showClientsListScreen();
			_goBackToMainMenue();
			break;

		case eMainMenueOptions::eAddNewClient:
			system("cls");
			_showAddNewClentScreen();
			_goBackToMainMenue();
			break;

		case eMainMenueOptions::eDeleteClient:
			system("cls");
			_showDeleteClientScreen();
			_goBackToMainMenue();
			break;

		case eMainMenueOptions::eUpdateClient:
			system("cls");
			_showUpdateClient();
			_goBackToMainMenue();
			break;

		case eMainMenueOptions::eFindClient:
			system("cls");
			_showFindClient();
			_goBackToMainMenue();
			break;

		case eMainMenueOptions::eTransactions:
			system("cls");
			_showTransactionsScreen();
			_goBackToMainMenue();
			break;

		case eMainMenueOptions::eManageUsers:
			system("cls");
			_showManageUsersScreen();
			_goBackToMainMenue();
			break;

		case eMainMenueOptions::eLoginRegister:
			system("cls");
			_showLoginRegisterScreen();
			_goBackToMainMenue();
			break;

		case eMainMenueOptions::eCurrencyExchange:
			system("cls");
			_showCurrencyExchangeScreen();
			_goBackToMainMenue();
			break;

		case eMainMenueOptions::eLogout:
			system("cls");
			_logout();
			break;
		}
	}

public:

	static void showMainMenueOptions() {


		showScreenHeader("Main Screen");

		cout << "\t\t\t\t [1]  Show Clients List\n";
		cout << "\t\t\t\t [2]  Add New Client\n";
		cout << "\t\t\t\t [3]  Delete Client\n";
		cout << "\t\t\t\t [4]  Update Client\n";
		cout << "\t\t\t\t [5]  Find Client\n";
		cout << "\t\t\t\t [6]  Transactions\n";
		cout << "\t\t\t\t [7]  Manage Users\n";
		cout << "\t\t\t\t [8]  Login Register\n";
		cout << "\t\t\t\t [9]  Currency Exchange\n";
		cout << "\t\t\t\t [10] Logout\n";

		cout << "\t\t\t"; Utility::tab(50);

		_performMainMenueOption((eMainMenueOptions)_readMainMenueOption());
	}
};

