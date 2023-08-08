#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "Global.h";
#include "clsUser.h";
#include "clsInputValidate.h";
#include "clsMainScreen.h";
#include "clsPeriod.h";
#include "Utility.h";


using namespace std;


class clsLoginScreen : protected clsScreen
{
private :

	static void _login() {
		string userName, password;
		bool loginFailed = true;
		
		while (loginFailed) {

			if (loginTrials == 0) {
				return;
			}

			loginTrials--;

			cout << "User Name : ";
			userName = clsInputValidate::readString();
			
			cout << "Enter Password : ";
			password = clsInputValidate::readString();

			if (clsUser::find(userName, password).isEmpty()) {

				cout << "Invalid User Name / Password , You Have " << (loginTrials) << " Trials !" << endl;
				continue;
			}

			loginFailed = false;
		}

		loginTrials = 3;
		currentUser = clsUser::find(userName, password);
		currentUser.addLoginInfoLineToFile();
		system("cls");
		clsMainScreen::showMainMenueOptions();
	}

public:

	static void showLoginScreen() {
		showScreenHeader("Login Screen");
		_login();
	}


};

