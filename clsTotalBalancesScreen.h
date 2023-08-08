#pragma once
#include <bits/stdc++.h>
#include "clsScreen.h";
#include "clsClient.h";


using namespace std;

class clsTotalBalancesScreen : protected clsScreen
{

public:
	
	static void showTotalBalancesScreen() {
		vector<clsClient> v = clsClient::getClientsList();
		double total = 0;

		string title = "Total Balances Screen", subTitle = "Clients (" + to_string(v.size()) + " )";
		showScreenHeader(title, subTitle);

		Utility::tab(80);

		cout << left << setw(25) << "| Acount Number";
		cout << left << setw(25) << "| Client Name";
		cout << left << setw(25) << "| Balance" << endl;

		Utility::tab(80);


		for (clsClient& temp : v) {
			cout << left << setw(25) << "| " + temp.AccountNumber;
			cout << left << setw(25) << "| " + temp.fullName();
			cout << left << setw(25) << "| " + to_string(temp.Balance) << endl;
			total += temp.Balance;
		}

		if (v.size() == 0) {
			cout << "\n" << right << setw(50) << "The System Has No Information ! \n" << endl;
		}

		Utility::tab(80);

		cout << right << setw(40) << "Total Balance Is : " << total << "\n" << endl;
		cout << right << setw(40) << "\t\t" + Utility::NumberToText((int)total) << "\n" << endl;

	}

};

