#pragma once

#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsClient.h";
#include "clsInputValidate.h";

using namespace std;

class clsDeleteClientScreen : protected clsScreen
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

	static void showDeleteClientScreen() {

		if (!checkAccessRights(clsUser::eDeleteClients)) {
			return;
		}

		showScreenHeader("Delete Client Screen");

		cout << "Enter The Client Account Number : ";
		string accNumber = clsInputValidate::readString();

		while (!clsClient::isClientExist(accNumber)) {
			cout << "Invalid ACC Number , Enter Another ACC Number : ";
			accNumber = clsInputValidate::readString();
		}
		clsClient client = clsClient::find(accNumber);
		_printClientCard(client);

		bool del = clsInputValidate::readDecision("Are You Sure You Want To Delete This Client ? ");

		if (del) {
			if (client.Delete()) {
				cout << "Client Deleted :)\n" << endl;
				_printClientCard(client);
			}
			else {
				cout << "\nError Client Was Not Deleted !" << endl;
			}
		}
	}

};

