//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#define ll long long
using namespace std;

//  6
// 18
//128
// ==> include <iomanip>
void display() {
	cout << setw(3) << 6 << endl << setw(3) << 18 << endl << setw(3) << 128
			<< endl;
}

// 2.000
// 2.500
// 2.958
// 2.958
void __setprecision() {
	double a = 2;
	double b = 2.5;
	double c = 2.95812346;
	cout << fixed << setprecision(3) << a << endl;
	cout << fixed << setprecision(3) << b << endl;
	cout << fixed << setprecision(3) << c << endl;
	cout << setw(1) << fixed << setprecision(3) << c << endl;

	// after display the effect off setprecision will continue thats mean a ==> 2.000
}

// ---------  setiosflags --------------
void iosflag() {
	cout << "|" << setw(20) << 142.1 << "|\n";
	cout << "|" << setw(20) << setiosflags(ios::left) << 142.1 << "|";
	cout << "|" << setw(20) << setiosflags(ios::scientific) << 142.1 << "|";
	cout << "|" << setw(20) << setiosflags(ios::fixed) << 142.1 << "|";
}

// Base Conversion

void base_conversion() {
	cout << "the decimal value of 15 is " << 15 << endl;
	cout << "the octal value of 15 is " << showbase << oct << 15 << endl;
	cout << "the hexadecimal of 15 is " << showbase << hex << 15 << endl;
	cout << "the hexadecimal value of 15 is " << showbase << uppercase << hex
			<< endl;

	cout << showbase << dec; // back to decimal;
	cout << "the decimal value of 025 is " << 025 << endl;		// ==> 21
	cout << "the decimal value of 0x37 is " << 0x37 << endl; 	// ==> 55
}

// Working with string

//	mostafa|saad|175
//  mostafa
//	saad
//	175
void read() {
	string firstname;
	string secondname;
	double salary;
	getline(cin, firstname, '|');
	getline(cin, secondname, '|');
	cin >> salary;
}

// #include <sstream>
void string_stream() {
	string data = "10 mostafa 5.7";

	int inum;
	string name;
	double dnum;

	istringstream iss(data);

	iss >> inum >> name >> dnum;
	cout << inum << endl;
	cout << name << endl;
	cout << dnum << endl;
}

//validate input
void validate() {
	cout << "Please Enter 2 Integers to get their sum: \n";
	int inum1, num2;
	cin >> inum1 >> num2;
	if (cin.fail()) {
		cout << "Invalid Input Got one more trail \n";
		cin.clear();					// make no problem appear
		cin.ignore(10000, '\n');		// skip to the next new

		cin >> inum1 >> num2;
		if (cin.fail())
			cout << "Again bad input , bye \n";
		else
			cout << "sum = " << inum1 + num2 << endl;
	} else
		cout << "sum = " << inum1 + num2 << endl;

	// note you can use istringstream like
	// 		iss.fail();
}

//smart trick
void sm(){
	string s ;
	getline(cin , s);

	istringstream iss(s);
	char ch = iss.peek();

	if(!isdigit(ch))
		cout<< "it was a string"<<endl;
	else
		cout<<"it was a number"<<endl;
}
