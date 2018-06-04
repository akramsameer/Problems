//============================================================================
// Name        : Choosing.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
string s;
long long arr[257];
int main() {
	getline(cin, s);
	for (int i = 0 ; i< s.length() ; i++) {
		char c = s[i];
		arr[c]++;
	}
	long long  sum = 0 ;
	for(int i = 0 ; i < 257 ; i++){
		sum += (arr[i] * arr[i]);
	}
	cout << sum <<endl;
	return 0;
}
