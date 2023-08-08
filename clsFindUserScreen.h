#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsUser.h";
#include "clsInputValidate.h";


using namespace std;

class clsFindUserScreen : protected clsScreen
{

private:

	static void _printUserCard(clsUser u) {
		cout << "\nClient Card : \n" << endl;
		Utility::tab(10);
		cout << "First Name  \t: " << u.FirstName << endl;
		cout << "Last Name   \t: " << u.LastName << endl;
		cout << "Full Name   \t: " << u.fullName() << endl;
		cout << "Email       \t: " << u.Email << endl;
		cout << "Phone       \t: " << u.Phone << endl;
		cout << "User Name   \t: " << u.UserName << endl;
		cout << "Password    \t: " << u.Password << endl;
		cout << "Permissions \t: " << u.Permissions << endl;
		Utility::tab(10);
	}

public:

	static void showFindUserScreen() {

		showScreenHeader("Find User Screen");

		cout << "Enter User Name :";
		string userName = clsInputValidate::readString();

		while (!clsUser::isUserExist(userName)) {
			cout << "The User Not Found ,Enter User Name :";
			userName = clsInputValidate::readString();
		}

		_printUserCard(clsUser::find(userName));
	}


};

