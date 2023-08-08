#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsClient.h";


using namespace std;

class clsTransferScreen : protected clsScreen
{

private:

	static void _checkAccountNumberExistance(string& acc) {
		while (clsClient::find(acc).isEmpty()) {
			cout << "Invalid ACC Number Try Again ,Enter Another Account Number To Transfer From: ";
			acc = clsInputValidate::readString();
		}
	}

	static void _printShortClientCard(clsClient c) {

		cout << "\tClient Card " << endl;
		cout << "-------------------------------\n" << endl;
		cout << "\nFull Name    : " << c.fullName() << endl;
		cout << "Account Number :" << c.AccountNumber << endl;
		cout << "Balance        :" << c.Balance << endl;
		cout << "\n-------------------------------\n" << endl;

	}


public:

	static void showTransferScreen() {

		showScreenHeader("Transfer Screen");

		cout << "Enter Account Number To Transfer From : ";
		string acc1 = clsInputValidate::readString();

		_checkAccountNumberExistance(acc1);
		clsClient cFrom = clsClient::find(acc1);
		_printShortClientCard(cFrom);

		cout << "Enter Account Number To Transfer To : ";
		string acc2 = clsInputValidate::readString();

		_checkAccountNumberExistance(acc2);
		clsClient cTo = clsClient::find(acc2);
		_printShortClientCard(cTo);

		int amount;
		cout << "Ente Transfer Amount : ";
		amount = clsInputValidate::readIntNumberBetween("Invalid Number , Try Again !", 0, cFrom.Balance);

		if (clsInputValidate::readDecision("Are You Sure You Want To Transfer ?"))
		{
			cFrom.transfer(amount, cTo);
			cout << "\nDone Succesfully :) " << endl;

			_printShortClientCard(cFrom);
			_printShortClientCard(cTo);
		}
		else {
			cout << "Operation Canceled !" << endl;
		}
	}
};

