#pragma once

#include <bits\stdc++.h>
#include "Utility.h";
#include "clsUser.h";
#include "Global.h";
#include "clsDate.h";

using namespace std;


class clsScreen
{

protected:

	static bool checkAccessRights(clsUser::ePermissions permission) {

		if (!currentUser.checkAccessPermission(permission)) {
			cout << "\t\t\t"; Utility::tab(50);
			cout << "\n\t\t\t\t" << "Access Denied-Contact Your Admin !\n" << "\n";
			cout << "\t\t\t"; Utility::tab(50);
			return false;
		}
		else {
			return true;
		}
	}


	 static void showScreenHeader(string title,string subTitle = "") {
		

		cout << "\t\t\t"; Utility::tab(50);
		cout << "\n\t\t\t\t\t" << title << "\n";
		cout << "\t\t\t\t\t" << subTitle << "\n\n";
		cout << "\t\t\t"; Utility::tab(50);
		cout << "\n\t\t\tUser : " << currentUser.UserName << endl;
		cout << "\t\t\tDate : "; clsDate::GetSystemDate().Print(); cout << endl;
		cout << "\t\t\t"; Utility::tab(50);

	}


};

