//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#define ll long long
using namespace std;
string str;
int main() {
	cin >> str;
	for (int i = 0; i < str.size(); ++i) {
		if ('9' - str[i] < 5) {
			if('9' - str[i] == 0 && i == 0)continue;
			str[i] = '9' - str[i] + '0';
		}
	}

	cout << str <<endl;
	return 0;
}
