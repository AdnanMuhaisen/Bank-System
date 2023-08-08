#pragma once

#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsClient.h";

using namespace std;

class clsDepositeScreen : protected clsScreen
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

public:

	static void showDepositeScreen() {

		showScreenHeader("Deposite Screen");

		cout << "\t\t\tEnter Client Account Number ";
		string acc = clsInputValidate::readString();

		while (!clsClient::isClientExist(acc)) {
			cout << "Invalid Acc Number , Enter Another One !" << endl;
			acc = clsInputValidate::readString();
		}

		clsClient client = clsClient::find(acc);
		_printClientCard(client);

		cout << "Enter Amount To Deposite : ";
		int amount = clsInputValidate::readDoubleNumber("Invalid Number , Try Again!");

		if (clsInputValidate::readDecision("Are You Sure You Want To Deposite ? ")) {
			client.deposite(amount);
			cout << "Done Succesfully :)" << endl;
			cout << "Your New Balance Is : " << client.Balance << endl;
		}
		else {
			cout << "The Operation Was Canceled !" << endl;
		}
	}

};

