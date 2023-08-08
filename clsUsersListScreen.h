#pragma once
#include <bits\stdc++.h>
#include "clsScreen.h";
#include "clsUser.h";
#include "Utility.h";
#include "clsPerson.h";


using namespace std;



class clsUsersListScreen : protected clsScreen
{

private:

	static clsUser _convertLineToUserObject(string line, string del = "#\\\\#") {
		vector<string> words = clsString::Split(line, "#\\\\#");//return vector
		Utility::decryptText(words[5]);
		clsUser user(words[0], words[1], words[2], words[3], words[4], words[5], stoi(words[6]), 1);// 1 is Update Mode
		return user;
	}

	static vector<clsUser> _loadUsersFromFile(string fileName = "NoFile") {
		fstream myFile;
		vector<clsUser> v;
		myFile.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\UsersFile.txt", ios::in);

		string tempLine;
		while (getline(myFile, tempLine)) {
			v.push_back(_convertLineToUserObject(tempLine));
		}

		myFile.close();
		return v;
	}

	static void _printUserLine(clsUser temp) {
		cout << "\t" << left << setw(15) << " | " + temp.UserName + "  ";
		cout << left << setw(20) << "| " + temp.fullName() + " ";
		cout << left << setw(15) << "| " + temp.Phone + " ";
		cout << left << setw(20) << "| " + temp.Email + " ";
		cout << left << setw(15) << "| " + temp.Password + " ";
		cout << left << setw(5) << "| " + to_string(temp.Permissions) + " " + "\n";
	}


public:

	static void showUsersList() {

		vector<clsUser> v = _loadUsersFromFile();
		string title = "Users List Screen", subTitle = to_string(v.size()) + " Users( s )";

		showScreenHeader(title, subTitle);

		//header of users list

		cout << "\n\t";  Utility::tab(100);

		cout << "\t" << left << setw(15) << " | User Name ";
		cout << left << setw(20) << "| Full Name ";
		cout << left << setw(15) << "| Phone ";
		cout << left << setw(20) << "| Email ";
		cout << left << setw(15) << "| Password ";
		cout << left << setw(5) << "| Permissions\n";

		cout << "\n\t";  Utility::tab(100);

		for (clsUser& temp : v) {
			_printUserLine(temp);
		}

		cout << "\n\t"; Utility::tab(100); cout << endl;

	}


};

