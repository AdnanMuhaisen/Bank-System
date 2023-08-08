#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsClient.h";


using namespace std;

class clsWithdrawScreen : protected clsScreen
{

private:

	static void _printClientCard(clsClient c) {
		cout << "\nClient Card : \n" << endl;
		Utility::tab(10);
		cout << "First Name \t: " << c.FirstName << endl;
		cout << "Last Name  \t: " << c.LastName << endl;
		cout << "Full Name  \t: " << c.fullName() << endl;
		cout << "Email      \t: " << c.Email << endl;
		cout << "Phone      \t: " << c.Phone << endl;
		cout << "Acc. Number\t: " << c.AccountNumber << endl;
		cout << "Pin Code   \t: " << c.PinCode << endl;
		cout << "Balance    \t: " << c.Balance << endl;
		Utility::tab(10);
	}

	static bool _checkAmountToWithdraw(double amount,clsClient c) {
		return (amount <= c.Balance);
	}


public:

	static void showWithdrawScreen() {

		showScreenHeader("Withdraw Screen");

		string acc;
		cout << "\t\t\tEnter Account Number : ";
		acc = clsInputValidate::readString();

		while (!clsClient::isClientExist(acc)) {
			cout << "Invalid ACC Number , Try Again !" << endl;
			acc = clsInputValidate::readString();
		}

		clsClient client = clsClient::find(acc);
		_printClientCard(client);

		cout << "Enter Amout You Want To Withdraw : ";
		double amount = clsInputValidate::readDoubleNumber("Invalid Number , Try Again !");

		if (_checkAmountToWithdraw(amount, client) && clsInputValidate::isNumberDivisibleBy5(amount)) {
			if (clsInputValidate::readDecision("Are You Sure You Want To Perform This Transaction ?")) {
				client.withdraw(amount);
				cout << "\nDone Succesfully :)" << endl;
				cout << "Your New Balance Is : " << client.Balance << endl;
			}
		}
		else {
			cout << "Invalid Amount !" << endl;
		}
	}


};

