#pragma once

#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsClient.h";
#include "clsInputValidate.h";


class clsFindClientScreen : protected clsScreen
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

	static void showFindClientScreen() {

		if (!checkAccessRights(clsUser::eFindClient)) {
			return;
		}

		showScreenHeader("Find Clien Screen");

		cout << "Enter Client Account Number : ";
		string acc = clsInputValidate::readString();

		while (!clsClient::isClientExist(acc)) {
			cout << "Invalid ACC Number , Enter Another One !" << endl;
			acc = clsInputValidate::readString();
		}

		clsClient client = clsClient::find(acc);

		cout << "\nClient Found :)\n" << endl;
		_printClientCard(client);
	}


};

