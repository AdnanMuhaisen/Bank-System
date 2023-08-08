#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsUser.h";
#include "clsInputValidate.h";

using namespace std;

class clsAddNewUserScreen : protected clsScreen
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

	static void _readUserPermissions(int& p) {

		p = 0;
		cout << "Set User Permissions : \n" << endl;

		if (clsInputValidate::readDecision("List Clients : ")) {
			p |= clsUser::ePermissions::eListClients;
		}

		if (clsInputValidate::readDecision("Add Clients : ")) {
			p |= clsUser::ePermissions::eAddClients;
		}
		
		if (clsInputValidate::readDecision("Delete Clients : ")) {
			p |= clsUser::ePermissions::eDeleteClients;
		}

		if (clsInputValidate::readDecision("Update Clients : ")) {
			p |= clsUser::ePermissions::eUpdateClient;
		}

		if (clsInputValidate::readDecision("Find Clients : ")) {
			p |= clsUser::ePermissions::eFindClient;
		}

		if (clsInputValidate::readDecision("Transactions : ")) {
			p |= clsUser::ePermissions::eTransactions;
		}
		if (clsInputValidate::readDecision("Manage Users : ")) {
			p |= clsUser::ePermissions::eManageUsers;
		}

		if (clsInputValidate::readDecision("Login Register :")) {
			p |= clsUser::eLoginRegisterList;
		}

		if (p == 255) {
			p = -1;
		}
	}

	static void _readUserInfo(clsUser& u) {

		cout << "Enter First Name : ";
		u.FirstName = clsInputValidate::readString();

		cout << "Enter Last Name : ";
		u.LastName = clsInputValidate::readString();

		cout << "Enter Email : ";
		u.Email = clsInputValidate::readString();

		cout << "Enter Phone : ";
		u.Phone = clsInputValidate::readString();

		cout << "Enter Password : ";
		u.Password = clsInputValidate::readString();

		int per;
		_readUserPermissions(per);
		u.Permissions = per;
	}

public:

	static void showAddNewUserScreen() {
		showScreenHeader("Add New User Screen");

		cout << "Enter User Name : ";
		string userName = clsInputValidate::readString();

		while (clsUser::isUserExist(userName)) {
			cout << "The User Already Exist , Try Again !" << endl;

			cout << "Enter User Name : ";
			userName = clsInputValidate::readString();
		}

		clsUser newUser = clsUser::getAddNewUser(userName);
		_readUserInfo(newUser);

		clsUser::eSaveResults saveResult = newUser.save();

		switch (saveResult) {

		case clsUser::eFaildEmptyObject:
			cout << "User Added Failed :(\nEmpty User !" << endl;
			break;
		case clsUser::eFailedUserExist:
			cout << "The User Already Exist :( " << endl;
			break;
		case clsUser::eSucceeded:
			cout << "The User Added Succesfully:)" << endl;
			_printUserCard(newUser);
			break;

		}
	}

};

