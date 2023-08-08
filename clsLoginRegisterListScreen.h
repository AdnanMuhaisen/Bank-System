#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsUser.h";
#include "Utility.h";

using namespace std;

class clsLoginRegisterScreen : protected clsScreen
{

private:

	static void _printLoginRegisterRecord(clsUser::sLoginRegisterLine s) {

		cout << "\t\t" << left << setw(30) << "| " + s.timeAndDate;
		cout << left << setw(20) << "| " + s.userName;
		cout << left << setw(20) << "| " + s.password;
		cout << left << setw(3) << "| " + to_string(s.permissions) + "\n";

	}

public:

	static void showLoginRegisterListScreen() {

		if (!checkAccessRights(clsUser::eLoginRegisterList)) {
			return;
		}

		vector<clsUser::sLoginRegisterLine> v = clsUser::loadLoginInfoFromFile();

		string subTitle = "( " + to_string(v.size()) + " ) Records (s)";
		showScreenHeader("Login Register Screen", subTitle);

		cout << "\n\t\t"; Utility::tab(90);
		cout << "\t\t" << left << setw(30) << "| Date / Time";
		cout << left << setw(20) << "| UserName";
		cout << left << setw(20) << "| Password";
		cout << left << setw(20) << "| Permissions\n";
		cout << "\t\t"; Utility::tab(90);

		for (clsUser::sLoginRegisterLine& temp : v) {
			_printLoginRegisterRecord(temp);
		}

		cout << "\n\t\t"; Utility::tab(90);

	}


};

