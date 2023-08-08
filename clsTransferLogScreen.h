#pragma once
#include<bits\stdc++.h>
#include"clsScreen.h";
#include "Utility.h";


using namespace std;

class clsTransferLogScreen : protected clsScreen
{

private:

	struct sTransferOperationLine {
		string dateAndTime;
		string sAcc;
		string dAcc;
		int amount, sBalance, dBalance;
		string userName;
	};

	static vector<sTransferOperationLine> _loadTransferLogData() {
		fstream file;
		vector <sTransferOperationLine>v;
		file.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\TransferOperationsFile.txt", ios::in);

		string line;
		while (getline(file, line)) {
			v.push_back(_convertLineToTransferOperationStruct(line));
		}

		file.close();
		return v;
	}

	static sTransferOperationLine _convertLineToTransferOperationStruct(string line) {

		vector<string>words = clsString::Split(line, "#\\\\#");
		sTransferOperationLine temp;
		temp.dateAndTime = words[0];
		temp.sAcc = words[1];
		temp.dAcc = words[2];
		temp.amount = stoi(words[3]);
		temp.sBalance = stoi(words[4]);
		temp.dBalance = stoi(words[5]);
		temp.userName = words[6];

		return temp;
	}

	static void _printTransferLogLine(sTransferOperationLine s) {
		cout << "\t" << left << setw(30) << "| " + s.dateAndTime;
		cout << left << setw(10) << "| " + s.sAcc;
		cout << left << setw(10) << "| " + s.dAcc;
		cout << left << setw(10) << "| " + to_string(s.amount);
		cout << left << setw(15) << "| " + to_string(s.sBalance);
		cout << left << setw(15) << "| " + to_string(s.dBalance);
		cout << left << setw(15) << "| " + s.userName + "\n";
	}


public:

	static void showTransferLogScreen() {

		showScreenHeader("Transfer Operations Screen");

		cout <<"\n\t"; Utility::tab(100);
		cout <<"\t"<< left << setw(30) << "| Date/Time";
		cout << left << setw(10) << "| S-Acc";
		cout << left << setw(10) << "| D-Acc";
		cout << left << setw(10) << "| Amount";
		cout << left << setw(15) << "| S-Balance";
		cout << left << setw(15) << "| D-Balance";
		cout << left << setw(15) << "| User\n";
		Utility::tab(100);

		vector<sTransferOperationLine> v = _loadTransferLogData();

		for (sTransferOperationLine& temp : v) {
			_printTransferLogLine(temp);
		}

		Utility::tab(100);
	}

};

