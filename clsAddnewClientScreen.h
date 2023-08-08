#pragma once

#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsClient.h";
#include "clsUser.h";


using namespace std;

class clsAddnewClientScreen : protected clsScreen
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

	static void showAddNewClientScreen() {
	
		if (!checkAccessRights(clsUser::eAddClients)) {
			return;
		}

		showScreenHeader("Add New Client Screen");

		cout << "Enter The Client Account Number : ";
		string accountNumber = clsInputValidate::readString();

		while (clsClient::isClientExist(accountNumber)) {
			cout << "The Client Is Already Exist , Enter Another Account Number : ";
			accountNumber = clsInputValidate::readString();
		}

		clsClient client = clsClient::getAddNewClientObject(accountNumber);
		_readClientInfo(client);

		clsClient::enSaveResult saveResult = client.save();

		switch (saveResult) {

		case clsClient::svSucceeded:
			cout << "Client Added Succefully :)" << endl;
			_printClientCard(client);
			break;
		case clsClient::svFailedEmptyObject:
			cout << "Added Operation Failed :(" << endl;
			break;
		case clsClient::accountNumberExist:
			cout << "The Account Number Is Already Exist :(" << endl;
			break;

		}
	}


};

