#pragma once

#include<bits\stdc++.h>
#include "clsDate.h";

using namespace std;

class Utility
{
public:

	enum CharacterType {
		Small = 1,Capital = 2,Digit = 3, Mix = 4
	};

	static void callSrand() {
		srand(time(NULL));
	}

	static int randomNumber(int from, int to) {
		return rand() % (to - from + 1) + from;
	}

	static char getSmallRandomCharacter() {
		return (char)randomNumber(97, 122);
	}

	static char getCapitalRandomCharacter() {
		return (char)randomNumber(65, 91);
	}

	static short getRandomDigit() {
		return randomNumber(48, 57);
	}

	static char getMixRandomCharacter() {
		short charType = randomNumber(1, 3);
		switch (charType) {
		case CharacterType::Capital:
			return getCapitalRandomCharacter();
			break;
		case CharacterType::Small:
			return getSmallRandomCharacter();
			break;
		case CharacterType::Digit:
			return (char)getRandomDigit();
			break;
		}
	}

	static char getRandomCharacter(short charType) {
		switch (charType) {
		case CharacterType::Capital:
			return getCapitalRandomCharacter();
			break;
		case CharacterType::Small:
			return getSmallRandomCharacter();
			break;
		case CharacterType::Digit:
			return (char)getRandomDigit();

		case CharacterType::Mix:
			getMixRandomCharacter();
			break;
		}
	}

	static string generateRandomWord(short charType,int size) {
		string str = "";
		for (short i = 1; i <= size; i++)
		{
			str += getRandomCharacter(charType);
		}
		return str;
	}

	static string generateKey(short charType) {
		return generateRandomWord(charType, 4) + "-" + generateRandomWord(charType, 4) + "-" 
			+ generateRandomWord(charType, 4) + "-" + generateRandomWord(charType, 4);
	}

	static vector<string> generateKeys(short numberOfKeys,short charType) {
		vector<string> keys(numberOfKeys);
		for (string& temp : keys) {
			temp = generateKey(charType);
		}
		return keys;
	}

	static void swap(int& a, int& b) {
		int temp = a;
		a = b;
		b = temp;
	}

	static void swap(double& a, double& b) {
		double temp = a;
		a = b;
		b = temp;
	}

	static void swap(string& a, string& b) {
		string temp = a;
		a = b;
		b = temp;
	}

	static void swap(clsDate& d1, clsDate& d2) {
		clsDate temp = d1;
		d1 = d2;
		d2 = temp;
	}

	static void shuffleArray(int arr[], int size) {
		
		for (size_t i = 0; i < size; i++)
		{
			int index = randomNumber(0, size - 1);
			swap(arr[i], arr[index]);
		}
	}

	static void shuffleArray(string arr[], int size) {
		for (size_t i = 0; i < size; i++)
		{
			int index = randomNumber(0, size - 1);
			swap(arr[i], arr[index]);
		}
	}

	static void fillArrayWithRandomNumbers(int arr[], int size,int from,int to) {
		for (short i = 0; i < size; i++)
		{
			arr[i] = randomNumber(from, to);
		}
	}

	static void fillArrayWithRandomWords(string arr[], int size, short charType, int lengthOfEachWord) {
		for (short i = 0; i < size; i++)
		{
			arr[i] = generateRandomWord(charType, lengthOfEachWord);
		}
	}

	static void fillArrayWithRandomKeys(string arr[], int size, short charType) {
		for (short i = 0; i < size; i++)
		{
			arr[i] = generateKey(charType);
		}
	}

	const static  short EncryptionKey = 2;
	//encryption key must be constant..
	static void encryptText(string& text, short encryptionKey = EncryptionKey) {
		for (char& temp : text) {
			temp = (char)(((int)temp) - encryptionKey);
		}
	}

	static void decryptText(string& text, short encryptionKey = EncryptionKey) {
		for (char& temp : text) {
			temp = (char)(((int)temp) + encryptionKey);
		}
	}

	static void tab(short times, char ch = '-') {
		for (short i = 1; i <= times; i++)
		{
			cout << ch;
		}
		cout << endl;
	}

	static string NumberToText(int Number)
	{

		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
		"Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
		  "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

			return  arr[Number] + " ";

		}

		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
			return  arr[Number / 10] + " " + NumberToText(Number % 10);
		}

		if (Number >= 100 && Number <= 199)
		{
			return  "One Hundred " + NumberToText(Number % 100);
		}

		if (Number >= 200 && Number <= 999)
		{
			return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}

		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumberToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
		}

		if (Number >= 1000000 && Number <= 1999999)
		{
			return  "One Million " + NumberToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
		}

		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return  "One Billion " + NumberToText(Number % 1000000000);
		}
		else
		{
			return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
		}


	}

	static string getCurrentTime() {

		time_t t = time(0);
		tm* now = localtime(&t);

		string hour = to_string(now->tm_hour);
		string minute = to_string(now->tm_min);
		string second = to_string(now->tm_sec);

		return hour + " : " + minute + " : " + second;
	}

};

