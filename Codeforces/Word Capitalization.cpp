//============================================================================
// Name        : Word.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
string str;
int main() {
	cin >> str;
	str[0] &= 223;
	cout<<str<<endl;
	return 0;
}
