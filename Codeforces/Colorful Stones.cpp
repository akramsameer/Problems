//============================================================================
// Name        : Colorful.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
string s, t;
int main() {
	cin >> s;
	cin >> t;
	int i , j = 0;
	for (i = 0; i < t.length(); i++) {
		if(t[i] == s[j])
			j++;
	}
	cout << j+1 <<endl;
	return 0;
}
