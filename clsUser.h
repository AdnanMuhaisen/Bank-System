#pragma once
#include <bits\stdc++.h>
#include "clsPerson.h";
#include "clsString.h";
#include "clsDate.h";
#include "Utility.h";


using namespace std;

class clsUser : public clsPerson
{

private:
	enum eMode { eEmptyMode, eUpdateMode, eAddNewMode };

	string _userName, _password;
	int _permissions;
	eMode _mode;


	static clsUser _convertLineToUserObject(string line, string del = "#\\\\#") {
		vector<string> words = clsString::Split(line, "#\\\\#");//return vector
		Utility::decryptText(words[5]);
		clsUser user(words[0], words[1], words[2], words[3], words[4], words[5], stoi(words[6]), eMode::eUpdateMode);
		return user;
	}

	static string _convertUserObjectToLine(clsUser u, string del = "#\\\\#") {
		string* tempPassword = new string;
		*tempPassword = u.Password;
		Utility::encryptText(*tempPassword);
		u.Password = *tempPassword;
		delete tempPassword;

		return u.FirstName + del + u.LastName + del + u.Email + del + u.Phone + del
			+ u.UserName + del + u.Password + del + to_string(u.Permissions);
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

	static void _uploadUsersToFile(vector <clsUser> v, string fileName = "noFile") {
		fstream file;
		file.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\UsersFile.txt", ios::out);

		vector<clsUser>::iterator it = v.begin();
		for (it = v.begin(); it != v.end(); it++) {
				file << "\n" + _convertUserObjectToLine(*it);
		}

		file.close();
	}

	static clsUser _getEmptyUserObject() {
		return clsUser("", "", "", "", "", "", 0, eMode::eEmptyMode);
	}

	void _update() {
		vector<clsUser>v = _loadUsersFromFile();

		for (clsUser& temp : v) {
			if (temp.UserName == this->UserName) {
				temp = *this;
				break;
			}
		}

		_uploadUsersToFile(v);
	}

	void _addNewLineToFile(string line) {
		fstream file;
		file.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\UsersFile.txt", ios::app);
		file << "\n" << line;
		file.close();
	}

	void _addNew() {
		_addNewLineToFile(_convertUserObjectToLine(*this));
	}


public:

	enum ePermissions {
		eAll = -1, eListClients = 1, eAddClients = 2, eDeleteClients = 4, eUpdateClient = 8, eFindClient = 16,
		eTransactions = 32, eManageUsers = 64 , eLoginRegisterList=128
	};

	
	clsUser(string firstName, string lastName, string email, string phone, string userName,
		string password, int permissions, short mode)
		: clsPerson(firstName, lastName, email, phone) {

		this->_userName = userName;
		this->_password = password;
		this->_permissions = permissions;
		this->_mode = (eMode)mode;
	}


	string fullName() {
		return this->FirstName + " " + this->LastName;
	}

	bool isEmpty() {
		return _mode == eMode::eEmptyMode;
	}

	void setUserName(string userName) {
		this->_userName = userName;
	}

	string getUserName() {
		return this->_userName;
	}

	void setPassword(string password) {
		this->_password = password;
	}

	string getPassword() {
		return this->_password;
	}

	void setPermissions(int permissions) {
		this->_permissions = permissions;
	}

	int getPermissions() {
		return this->_permissions;
	}

	__declspec(property(put = setUserName, get = getUserName)) string UserName;
	__declspec(property(put = setPassword, get = getPassword)) string Password;
	__declspec(property(put = setPermissions, get = getPermissions)) int Permissions;


	static clsUser find(string userName){
		fstream file;
		file.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\UsersFile.txt", ios::in);

		string line;
		while (getline(file, line)) {
			clsUser user = _convertLineToUserObject(line);

			if (user.UserName == userName) {
				file.close();
				return user;
			}
		}
		file.close();
		return _getEmptyUserObject();
	}

	static clsUser find(string userName, string password) {
		fstream file;
		file.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\UsersFile.txt", ios::in);

		string line;
		while (getline(file, line)) {
			clsUser user = _convertLineToUserObject(line);

			if (user.UserName == userName&&user.Password==password) {
				file.close();
				return user;
			}
		}
		file.close();
		return _getEmptyUserObject();
	}

	static bool isUserExist(string userName) {
		clsUser temp = clsUser::find(userName);
		return !(temp.isEmpty());
	}

	bool Delete() {
		vector<clsUser> vUsers = _loadUsersFromFile();
		vector<clsUser>::iterator it;

		for (it = vUsers.begin(); it != vUsers.end(); it++) {
			if ((*it).UserName == this->UserName) {
				vUsers.erase(it);
				break;
			}
		}
		_uploadUsersToFile(vUsers);
		*this = _getEmptyUserObject();

		return true;

	}

	enum eSaveResults { eFaildEmptyObject, eSucceeded, eFailedUserExist };

	eSaveResults save() {

		switch (_mode) {

		case eMode::eEmptyMode:
			if (isEmpty()) {
				return eSaveResults::eFaildEmptyObject;
			}
			break;

		case eSaveResults::eSucceeded:
			_update();
			return eSaveResults::eSucceeded;
			break;

		case eSaveResults::eFailedUserExist:
			if (isUserExist(this->UserName)) {
				return eSaveResults::eFailedUserExist;
			}
			else {
				_addNew();
				this->_mode = eMode::eUpdateMode;
				return eSaveResults::eSucceeded;
			}

			break;
		}


	}


	static clsUser getAddNewUser(string userName) {
		return clsUser("", "", "", "", userName, "", 0, eMode::eAddNewMode);
	}

	static vector<clsUser> getUsersList() {
		return _loadUsersFromFile();
	}

	bool checkAccessPermission(ePermissions permission) {
		if (this->_permissions == ePermissions::eAll) {
			return true;
		}

		if ((this->_permissions & permission) == permission) {
			return true;
		}
		else {
			return false;
		}
	}

	void addLoginInfoLineToFile(string delimiter = "#\\\\#") {

		fstream loginFile;
		loginFile.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\LoginFile.txt", ios::app);

		string* tempPassword = new string;
		*tempPassword = this->Password;
		Utility::encryptText(*tempPassword);
		this->Password = *tempPassword;
		delete tempPassword;

		loginFile << "\n" + clsDate::GetSystemDate().DateToString() + " - " + Utility::getCurrentTime() +
			delimiter + this->UserName + delimiter + this->Password + delimiter + to_string(this->Permissions);

		loginFile.close();
	}

	struct sLoginRegisterLine {
		string timeAndDate;
		string userName;
		string password;
		int permissions;
	};

	static sLoginRegisterLine convertLineToLoginStruct(string line) {

		sLoginRegisterLine temp;
		vector<string> words = clsString::Split(line, "#\\\\#");

		temp.timeAndDate = words[0];
		temp.userName = words[1];
		temp.password = words[2];
		temp.permissions = stoi(words[3]);
		Utility::decryptText(words[2]);

		return temp;
	}

	static vector<sLoginRegisterLine> loadLoginInfoFromFile(string fileName = "NoFile") {

		fstream myFile;
		myFile.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\LoginFile.txt", ios::in);
		vector<sLoginRegisterLine> v;

		string line;
		while (getline(myFile, line)) {
			v.push_back(convertLineToLoginStruct(line));
		}

		myFile.close();
		return v;
	}

};

