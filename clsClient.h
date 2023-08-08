#pragma once

#include <bits\stdc++.h>
#include "clsPerson.h";
#include "clsString.h";
#include "Utility.h";

using namespace std;

class clsClient : public clsPerson
{
private:

	static string _CLIENTS_FILE;

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _mode;

	string _accountNumber, _pinCode;
	double _balance;


	static clsClient _convertLineToClientObject(string line, string del= "#\\\\#") {
		vector<string> words = clsString::Split(line, "#\\\\#");//return vector
		clsClient clint(words[0], words[1], words[2], words[3], words[4], words[5], stod(words[6]),enMode::UpdateMode);
		return clint;
	}

	static string _convertClintObjectToLine(clsClient c,string del= "#\\\\#") {
		return c.FirstName + del + c.LastName + del + c.Email + del + c.Phone + del 
			+ c.AccountNumber + del + c.PinCode + del + to_string(c.Balance);
	}

	static clsClient _getEmptyClientObject() {
		clsClient temp("", "", "", "", "", "", 0.0,enMode::EmptyMode);
		return temp;
	}

	static vector<clsClient> _loadDataFromFile(string fileName) {
		fstream file;
		vector<clsClient>lines;

		file.open(fileName, ios::in);
		string temp;

		while (getline(file, temp)) {
			lines.push_back(_convertLineToClientObject(temp));
		}

		file.close();
		return lines;
	}

	void _uploadDataToFile(vector<clsClient> v) {
		fstream file;
		file.open(_CLIENTS_FILE, ios::out);

		vector<clsClient>::iterator it = v.begin();
		for (it = v.begin(); it != v.end(); it++) {

			if (it == v.end() - 1) 
				file << _convertClintObjectToLine(*it);			
			else
				file << _convertClintObjectToLine(*it) + "\n";

		}

		file.close();
	}

	void _update() {
		vector<clsClient>v = _loadDataFromFile(_CLIENTS_FILE);

		for (clsClient& temp : v) {
			if (temp.AccountNumber == this->AccountNumber) {
				temp = *this;
				break;
			}
		}

		_uploadDataToFile(v);
	}

	void _addNewLineToFile(string line) {
		fstream file;
		file.open(_CLIENTS_FILE, ios::app);
		file << "\n" << line;
		file.close();
	}

	void _addNew() {
		_addNewLineToFile(_convertClintObjectToLine(*this));
	}

	string _convertTransferInfoToLine(string accNumberForTargetClient,int balanceForTargetClient,int amount,string del="#\\\\#") {

		string str = clsDate::GetSystemDate().DateToString() + " - " + Utility::getCurrentTime() + del +
			this->AccountNumber + del + accNumberForTargetClient + del + to_string(amount) + del + to_string(this->Balance) + del +
			to_string(balanceForTargetClient) + del + currentUser.UserName;

		return str;
	}

	void _addTransgerOperationToFile(clsClient targetClient,int amount) {
		fstream transferFile;
		transferFile.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\TransferOperationsFile.txt", ios::app);
		transferFile <<"\n"+ _convertTransferInfoToLine(targetClient.AccountNumber, targetClient.Balance, amount);
		transferFile.close();
	}

public:

	clsClient(string firstName, string lastName, string email, string phone, string accountNumber, string pinCode, double balance,short mode)
	: clsPerson(firstName,lastName,email,phone){
	
		this->_accountNumber = accountNumber;
		this->_pinCode = pinCode;
		this->_balance = balance;
		this->_mode = (enMode)mode;
	}

	//properity set and get for Clint data members : 
	bool isEmpty() {
		return (enMode::EmptyMode == this->_mode);
	}

	string getAccountNumber() {
		return this->_accountNumber;
	}

	void setPinCode(string pinCode) {
		this->_pinCode = pinCode;
	}

	string getPinCode() {
		return this->_pinCode;
	}

	void setBalance(double balance) {
		this->_balance = balance;
	}

	double getBalance() {
		return _balance;
	}
	
	//declaration specification properites:
	__declspec(property(get = getAccountNumber)) string AccountNumber;
	__declspec(property(put = setPinCode, get = getPinCode)) string PinCode;
	__declspec(property(put = setBalance, get = getBalance))  double Balance;
	

	string fullName() {
		return FirstName + " " + LastName;
	}

	//No UI in Entity Object !

	//void print() {
	//	cout << "\nClient Card : \n" << endl;
	//	Utility::tab(10);
	//	cout << "First Name \t: " << FirstName << endl;
	//	cout << "Last Name  \t: " << LastName << endl;
	//	cout << "Full Name  \t: " << fullName() << endl;
	//	cout << "Email      \t: " << Email << endl;
	//	cout << "Phone      \t: " << Phone << endl;
	//	cout << "Acc. Number\t: " << AccountNumber << endl;
	//	cout << "Pin Code   \t: " << PinCode << endl;
	//	cout << "Balance    \t: " << Balance << endl;
	//	Utility::tab(10);
	//}

	//find and return the object if found 
	static clsClient find(string accountNumber) {
		fstream file;
		file.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\ClientsFile.txt",ios::in);
		
		string line;
		while (getline(file, line)) {
			clsClient client = _convertLineToClientObject(line);
			
			if (client.AccountNumber == accountNumber) {
				file.close();
				return client;
			}
		}
		file.close();
		return _getEmptyClientObject();
	}

	static clsClient find(string accountNumber, string pinCode) {
		fstream file;
		file.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\ClientsFile.txt");

		string line;
		while (getline(file, line)) {
			clsClient client = _convertLineToClientObject(line);

			if (client.AccountNumber == accountNumber && client.PinCode==pinCode) {
				file.close();
				return client;
			}
		}
		file.close();
		return _getEmptyClientObject();
	}

	//check if the client store data
	static bool isClientExist(string accountNumber) {
		clsClient client = clsClient::find(accountNumber);
		return !client.isEmpty();
	}
	
	static clsClient getAddNewClientObject(string accNumber) {
		return clsClient("", "", "", "", accNumber, "", 0, enMode::AddNewMode);
	}

	bool Delete() {
		vector<clsClient> vClients = _loadDataFromFile(_CLIENTS_FILE);
		vector<clsClient>::iterator it;

		for (it = vClients.begin(); it != vClients.end(); it++) {
			if ((*it).AccountNumber == this->AccountNumber) {
				vClients.erase(it);
				break;
			}
		}
		_uploadDataToFile(vClients);
		*this = _getEmptyClientObject();

		return true;
	}

	static vector<clsClient> getClientsList() {
		return _loadDataFromFile(_CLIENTS_FILE);
	}

	//this enum to save the data on the file 
	enum enSaveResult { svSucceeded, svFailedEmptyObject, accountNumberExist };

	enSaveResult save() {
		switch (_mode) {

		case enMode::EmptyMode:
			return enSaveResult::svFailedEmptyObject;
			break;

		case enMode::UpdateMode:
			_update();
			return enSaveResult::svSucceeded;
			break;

		case enMode::AddNewMode:
			if (clsClient::isClientExist(this->AccountNumber)) {
				return enSaveResult::accountNumberExist;
			}
			else {
				_addNew();
				this->_mode = enMode::UpdateMode;
				return enSaveResult::svSucceeded;
			}
			break;

		}
	}

	void withdraw(int amount) {
		this->Balance -= amount;
		save();
	}

	void deposite(int amount) {
		if (amount > 0) {
			this->Balance += amount;
			save();
		}
		else {
			cout << "Invalid Operation !" << endl;
		}
	}

	void transfer(int amount, clsClient& to) {

		this->withdraw(amount);
		to.deposite(amount);
		_addTransgerOperationToFile(to, amount);
	}

};

string clsClient::_CLIENTS_FILE = "C:\\C++-projects\\OOP-Projects\\Bank-System\\ClientsFile.txt";