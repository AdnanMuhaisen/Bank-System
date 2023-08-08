#pragma once

#include <bits\stdc++.h>
#include "clsScreen.h";
#include "Utility.h";
#include "clsInputValidate.h";
#include "clsMainScreen.h";
#include "clsDepositeScreen.h";
#include "clsWithdrawScreen.h";
#include "clsTotalBalancesScreen.h";
#include "clsTransferScreen.h";
#include "clsTransferLogScreen.h";


using namespace std;

class clsTransactionsScreen : protected clsScreen
{
private:

	enum eTransactions {
		eDeposite = 1, eWithdraw = 2, eTotalBalances = 3, eTransferScreen = 4, transferLogScreen = 5, eGoBakToMainMenue = 6
	};

	static short _readTransactionOption() {
		short option = clsInputValidate::readIntNumberBetween("Invalid Number , Try Again !", 1, 6); cout << endl;
		return option;
	}

	static void _goBackToTransactionsMenue() {
		cout << "\nPrees Any Key To Go Back To Transactions Menue .. \n" << endl;
		system("pause");
		system("cls");
		showTransactionsMenue();
	}

	static void _showDepositeScreen() {
		clsDepositeScreen::showDepositeScreen();
	}

	static void _showWithdrawScreen() {
		clsWithdrawScreen::showWithdrawScreen();
	}

	static void _showTotalBalancesScreen() {
		clsTotalBalancesScreen::showTotalBalancesScreen();
	}

	static void _showTransferScreen() {
		clsTransferScreen::showTransferScreen();
	}

	static void _showTransferLogScreen() {
		clsTransferLogScreen::showTransferLogScreen();
	}

	static void _doTransactionOption(eTransactions option) {

		switch (option) {

		case eTransactions::eDeposite:
			system("cls");
			_showDepositeScreen();
			_goBackToTransactionsMenue();
			break;
			
		case eTransactions::eWithdraw:
			system("cls");
			_showWithdrawScreen();
			_goBackToTransactionsMenue();
			break;

		case eTransactions::eTotalBalances:
			system("cls");
			_showTotalBalancesScreen();
			_goBackToTransactionsMenue();
			break;

		case eTransactions::eTransferScreen:
			system("cls");
			_showTransferScreen();
			_goBackToTransactionsMenue();
			break;

		case eTransactions::transferLogScreen:
			system("cls");
			_showTransferLogScreen();
			_goBackToTransactionsMenue();
			break;

		case eTransactions::eGoBakToMainMenue:
			//the system implecitly handle this case !
			break;
		}
	}

public:

	static void showTransactionsMenue() {

		if (!checkAccessRights(clsUser::eTransactions)) {
			return;
		}

		showScreenHeader("Transactions Screen");

		cout << "\t\t\t"; Utility::tab(50);
		cout << "\t\t\t\t[1] Deposite\n";
		cout << "\t\t\t\t[2] Withdraw\n";
		cout << "\t\t\t\t[3] Total Balances\n";
		cout << "\t\t\t\t[4] Transfer Screen\n";
		cout << "\t\t\t\t[5] Transfer Log\n";
		cout << "\t\t\t\t[6] Go To Main Menue\n";
		cout << "\t\t\t"; Utility::tab(50);

		cout << "\t\t\tChoose What Do You Want To Do ? [1,4] ";
		_doTransactionOption((eTransactions)_readTransactionOption());
	}

};

