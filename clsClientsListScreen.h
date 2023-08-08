#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsClient.h";




using namespace std;

class clsClientsListScreen : protected clsScreen
{
private:

	static void _printClientLine(clsClient c) {
		cout << left << setw(20) << "| " + c.AccountNumber;
		cout << left << setw(15) << "| " + c.FirstName;
		cout << left << setw(15) << "| " + c.LastName;
		cout << left << setw(20) << "| " + c.Email;
		cout << left << setw(15) << "| " + c.Phone;
		cout << left << setw(15) << "| " + c.PinCode;
		cout << left << setw(15) << "| " + to_string(c.Balance) << endl;
	}

public:


	static void showClientsListScreen() {

		if (!checkAccessRights(clsUser::eListClients)) {
			return;
		}
		vector<clsClient> v = clsClient::getClientsList();

		string title = "Clients List Screen "
			, subTitle = "Clents( " + to_string(v.size()) + " )";

		showScreenHeader(title, subTitle);

		cout << "\n" << left << setw(20) << "| Account Number ";
		cout << left << setw(15) << "| First Name ";
		cout << left << setw(15) << "| Last Name ";
		cout << left << setw(20) << "| Email ";
		cout << left << setw(15) << "| Phone ";
		cout << left << setw(15) << "| Pin Code ";
		cout << left << setw(15) << "| Balance " << "\n\n";
		Utility::tab(120);

		for (clsClient& temp : v) {
			_printClientLine(temp);
		}

		if (v.size() == 0) {
			cout << "\n" << right << setw(70) << "The System Has No Information ! \n" << endl;
		}

		Utility::tab(120);

	}


};

