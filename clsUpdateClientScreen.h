#pragma once

#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsClient.h";
#include "clsInputValidate.h";


class clsUpdateClientScreen : protected clsScreen
{
private:

	static void _readClientInfo(clsClient& client) {

		string str;
		cout << "\n";

		cout << "Enter First Name : ";
		str = clsInputValidate::readString();
		client.setFirstName(str);

		cout << "Enter Last Name : ";
		str = clsInputValidate::readString();
		client.setLastName(str);

		cout << "Enter Email : ";
		str = clsInputValidate::readString();
		client.setEmail(str);

		cout << "Enter Phone : ";
		str = clsInputValidate::readString();
		client.setPhone(str);

		cout << "Enter Pin Code : ";
		str = clsInputValidate::readString();
		client.setPinCode(str);

		cout << "Enter Balance : ";
		double balance = clsInputValidate::readDoubleNumber("Invalid Number !");
		client.setBalance(balance);

	}

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

	static void showUpdateClientScreen() {

		if (!checkAccessRights(clsUser::eUpdateClient)) {
			return;
		}

		showScreenHeader("Update Client Screen");

		cout << "Please Enter Client Account Number : ";
		string acc = clsInputValidate::readString();

		while (!clsClient::isClientExist(acc)) {
			cout << "Please Enter Client Account Number : ";
			acc = clsInputValidate::readString();
		}
		clsClient client = clsClient::find(acc);
		_printClientCard(client);

		cout << "\nUpdate Client : \n" << endl;
		Utility::tab(10);

		_readClientInfo(client);

		clsClient::enSaveResult save = client.save();

		switch (save) {
		case clsClient::svSucceeded:
			cout << "Updated Succesfully :)" << endl;
			break;
		case clsClient::svFailedEmptyObject:
			cout << "Update Failed :(" << endl;
			break;
		}
	}

};

