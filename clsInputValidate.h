#pragma once

#include <bits\stdc++.h>
#include "clsDate.h";
#include"Utility.h";


using namespace std;

class clsInputValidate
{

private:

	static int readIntNumberWithoutValidation() {
		int x;
		cin >> x;
		cout << endl;
		return x;
	}

public:

	static bool isNumberBetween(int number, int from, int to) {

		if (from > to) {
			Utility::swap(from, to);
		}

		return (number >= from) && (number <= to);
	}

	static bool isNumberBetween(double number, double from, double to) {

		if (from > to) {
			Utility::swap(from, to);
		}

		return (number >= from) && (number <= to);
	}

	static bool isDateBetween(clsDate date, clsDate from, clsDate to) {

		if (clsDate::IsDate1AfterDate2(from, to)) {
			Utility::swap(from, to);
		}

		return (clsDate::IsDate1AfterDate2(date, from) || clsDate::IsDate1EqualDate2(date, from))
			&& (clsDate::IsDate1BeforeDate2(date, to) || clsDate::IsDate1EqualDate2(date, to));
	}

	static bool isValidDate(clsDate Date) {
		return clsDate::IsValidDate(Date);
	}

	static string readString() {
		string str;
		getline(cin >> ws, str);
		cout << endl;
		return str;
	}

	static int readIntNumber(string errorMessage) {
		
		int number;
		bool displayErrorMessage = false;

		do {

			if (displayErrorMessage) {
				cout << errorMessage << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			//cout << "Please Enter A Number : ";
			cin >> number; cout << endl;

			displayErrorMessage = true;
		} while (cin.fail());

		return number;
	}

	static int readIntNumberBetween(string errorMessage, int from, int to) {
		int number;
		bool displayErrorMessage = false;

		do {
			if (displayErrorMessage)
				cout << errorMessage << endl;

			number = readIntNumber("Invalied Number , Try Again !");
			displayErrorMessage = true;
		} while (!(number >= from) || !(number <= to));
		return number;
	}

	static double readDoubleNumber(string errorMessage) {
		double number;
		bool displayErrorMessage = false;

		do {

			if (displayErrorMessage) {
				cout << errorMessage << endl;
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}

			//cout << "Please Enter A Number : ";
			cin >> number; cout << endl;

			displayErrorMessage = true;
		} while (cin.fail());

		return number;
	}

	static double readDoubleNumberBetween(string errorMessage, double from, double to) {
		double number;
		bool displayErrorMessage = false;

		do {
			if (displayErrorMessage)
				cout << errorMessage << endl;

			number = readIntNumber("Invalied Number , Try Again !");
			displayErrorMessage = true;
		} while (!(number >= from) || !(number <= to));
		return number;
	}

	static bool readDecision(string message) {
		char decision = false;
		cout << "\n" + message + " [y/n] ";
		cin >> decision; cout << endl;

		return tolower(decision) == 'y' ? true : false;
	}

	static bool isNumberDivisibleBy5(int n) {
		return (n % 5 == 0);
	}

	
};

