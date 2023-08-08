#pragma once

#include<bits\stdc++.h>

using namespace std;

class clsPerson
{
private:
	string _firstName, _lastName, _email, _phone;
		
public:
	clsPerson(string firstName, string lastName, string email, string phone) {
		this->_firstName = firstName;
		this->_lastName = lastName;
		this->_email = email;
		this->_phone = phone;
	}

	// properity set and get for all data members :
	void setFirstName(string firstName) {
		this->_firstName = firstName;
	}

	string getFirstName() {
		return this->_firstName;
	}

	void setLastName(string lastName) {
		this->_lastName = lastName;
	}

	string getLastName() {
		return this->_lastName;
	}

	void setEmail(string email) {
		this->_email = email;
	}

	string getEmail() {
		return this->_email;
	}

	void setPhone(string phone) {
		this->_phone = phone;
	}

	string getPhone() {
		return this->_phone;
	}

	//declaration specification properites for all data members:
	__declspec(property(put = setFirstName, get = getFirstName)) string FirstName;
	__declspec(property(put = setLastName, get = getLastName)) string LastName;
	__declspec(property(put = setEmail, get = getEmail)) string Email;
	__declspec(property(put = setPhone, get = getPhone)) string Phone;



};

