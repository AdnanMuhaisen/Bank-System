#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "Utility.h";
#include "clsInputValidate.h";
#include "clsUsersListScreen.h";
#include "clsAddNewUserScreen.h";
#include "clsDeleteUserScreen.h";
#include "clsUpdateUserScreen.h";
#include "clsFindUserScreen.h";



class clsManageUsersScreen : protected clsScreen
{
private:

	enum eManageUsersOptions {
		eListUsers=1,eAddUsers=2,eDeleteUser=3,eUpdateUser=4,eFindUser=5,eMainMenue=6
	};

	static short _readManageUsersOption() {
		cout << "\t\t\tChoose What Do You Want To Do :  [1 , 6]";
		short option = clsInputValidate::readIntNumberBetween("Imvalid Choice , Try Again !", 1, 6);
		return option;
	}

	static void _goBackToManageUsersMenue() {
		cout << "\nPrees Any Key To Go Back To Manage Users Menue .. \n" << endl;

		system("pause");
		system("cls");
		showManageUsersScreen();
	}

	static void _listUsersScreen() {
		clsUsersListScreen::showUsersList();
	}

	static void _addUserScreen() {
		clsAddNewUserScreen::showAddNewUserScreen();
	}

	static void _deleteUserScreen() {
		clsDeleteUserScreen::showDeleteUserScreen();
	}
	
	static void _updateUserScreen() {
		clsUpdateUserScreen::showUpdateUserScreen();
	}
	
	static void _findUserScreen() {
		clsFindUserScreen::showFindUserScreen();
	}

	static void _perormManageUsersOption(eManageUsersOptions option) {

		switch (option) {
		case eManageUsersOptions::eListUsers:
			system("cls");
			_listUsersScreen();
			_goBackToManageUsersMenue();
			break;

		case eManageUsersOptions::eAddUsers:
			system("cls");
			_addUserScreen();
			_goBackToManageUsersMenue();
			break;

		case eManageUsersOptions::eDeleteUser:
			system("cls");
			_deleteUserScreen();
			_goBackToManageUsersMenue();
			break;
		case eManageUsersOptions::eUpdateUser:
			system("cls");
			_updateUserScreen();
			_goBackToManageUsersMenue();
			break;		
		case eManageUsersOptions::eFindUser:
			system("cls");
			_findUserScreen();
			_goBackToManageUsersMenue();
			break;
		case eManageUsersOptions::eMainMenue:
			system("cls");
			//the system by default handle this case !
			break;
		}
	}

public:


	static void showManageUsersScreen() {

		if (!checkAccessRights(clsUser::eManageUsers)) {
			return;
		}

		showScreenHeader("Manage Users Screen");

		cout << "\t\t\t"; Utility::tab(50);
		cout << "\n\t\t\t\t\t" << "Manage Users Menue\n" << endl;
		cout << "\t\t\t"; Utility::tab(50);

		cout << "\t\t\t\t\t[1] List Users" << endl;
		cout << "\t\t\t\t\t[2] Add User" << endl;
		cout << "\t\t\t\t\t[3] Delete User" << endl;
		cout << "\t\t\t\t\t[4] Update User" << endl;
		cout << "\t\t\t\t\t[5] Find User" << endl;
		cout << "\t\t\t\t\t[6] Main Menue" << endl;

		cout << "\t\t\t"; Utility::tab(50);

		_perormManageUsersOption((eManageUsersOptions)_readManageUsersOption());

	}

};

