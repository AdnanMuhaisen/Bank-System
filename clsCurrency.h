#pragma once
#include <bits\stdc++.h>
#include "clsString.h";


using namespace std;


class clsCurrency
{
	//C:\C++-projects\OOP-Projects\Bank-System\\Currencies.txt
private:

	enum eMode;//declare the enum

	string _countryName, _currencyCode, _currencyName;
	float _exchangeRate;// In Dollar
	eMode _mode;

	static clsCurrency _getEmptyCurrencyObject() {
		return clsCurrency("", "", "", 0, eMode::eEmptyMode);
	}


	static clsCurrency _convertLineToCurrency(string line,string del="#//#") {
		vector<string>words = clsString::Split(line, del);
		clsCurrency temp = _getEmptyCurrencyObject();

		temp._countryName = words[0];
		temp._currencyCode = words[1];
		temp._currencyName = words[2];
		temp._exchangeRate = stof(words[3]);
		
		return temp;
	}

	static string _convertCurrencyObjectToLine(clsCurrency obj,string del="#//#") {
		return obj.CountryName + del + obj.CurrencyCode + del + obj.CurrencyName + del + to_string(obj.ExchangeRate);
	}

	static vector<clsCurrency> _loadCurrenciesFromFile() {

		fstream file;
		vector<clsCurrency> v;
		file.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\Currencies.txt", ios::in);

		string line;
		while (getline(file, line)) {
			v.push_back(_convertLineToCurrency(line));
		}

		file.close();
		return v;
	}

	static void _uploadCurrenciesToFile(vector<clsCurrency> v) {
		fstream file;
		file.open("C:\\C++-projects\\OOP-Projects\\Bank-System\\Currencies.txt", ios::out);

		vector<clsCurrency>::iterator it;
		for (it = v.begin(); it != v.end(); it++) {
			if (it == v.begin())
				file << _convertCurrencyObjectToLine(*it);
			else
				file << "\n" + _convertCurrencyObjectToLine(*it);
		}

		file.close();
	}

	void _update() {
		vector<clsCurrency> v = _loadCurrenciesFromFile();
		for (clsCurrency& temp : v) {
			if (temp.CurrencyCode == this->CurrencyCode) {
				temp = *this;
				break;
			}
		}
		_uploadCurrenciesToFile(v);
	}

public:

	enum eMode {
		eEmptyMode, eUpdateMode
	};

	clsCurrency(string countryName, string currencyCode, string currencyName, float rate, eMode mode) {

		this->_countryName = countryName;
		this->_currencyCode = currencyCode;
		this->_currencyName = currencyName;
		this->_exchangeRate = rate;
	}

	bool isEmpty() {
		return (_mode == eEmptyMode);
	}

	string getCountryName() {
		return this->_countryName;
	}

	string getCurrencyCode() {
		return this->_currencyCode;
	}

	string getCurrencyName() {
		return this->_currencyName;
	}

	void updateExchangeRate(float rate) {
		this->_exchangeRate = rate;
		_update();
	}

	float getExchangeRate() {
		return this->_exchangeRate;
	}


	__declspec(property(get = getCountryName))string CountryName;
	__declspec(property(get = getCurrencyCode))string CurrencyCode;
	__declspec(property(get = getCurrencyName))string CurrencyName;
	__declspec(property(get = getExchangeRate, put = updateExchangeRate))float ExchangeRate;

	static clsCurrency findByCode(string code) {
		vector<clsCurrency> v = _loadCurrenciesFromFile();

		for (clsCurrency& temp : v) {
			if (clsString::UpperAllString(temp.CurrencyCode) == clsString::UpperAllString(code)) {
				return temp;
			}
		}

		return _getEmptyCurrencyObject();
	}

	static clsCurrency findByCountry(string country) {
		vector<clsCurrency> v = _loadCurrenciesFromFile();
		
		for (clsCurrency& temp : v) {
			if (clsString::UpperAllString(temp.CountryName) == clsString::UpperAllString(country)) {
				return temp;
			}
		}

		return _getEmptyCurrencyObject();
	}

	static bool isCurrencyExist(string code) {
		return !(clsCurrency::findByCode(code).isEmpty());
	}

	static vector<clsCurrency> getCurrenciesList() {
		return _loadCurrenciesFromFile();
	}

	float calculateAmountInDollar(float amount) {
		//return the amount from this currency in dollar
		return amount / this->ExchangeRate;
	}

	float calculateAmountInAnyCurrency(clsCurrency to,float amount) {

		if (clsString::UpperAllString(to.CurrencyCode) == "USD") {
			return this->calculateAmountInDollar(amount);
		}

		float temp = amount / this->ExchangeRate;//current currency cnverted to dollar
		return temp * to.ExchangeRate;
	}

};

