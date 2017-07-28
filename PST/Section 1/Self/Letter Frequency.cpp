//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int t , arr[26] , ma =  0;
string temp;
int main() {
	cin >> t ;
	while(t--){
		getchar();
		getline(cin , temp);
		for (int i = 0; i < temp.size(); ++i) {
			int ps =tolower(temp[i]) - 'a';
			arr[ps] ++;
		}
		for (int i = 0; i < 26; ++i) {
			if(arr[i] > ma)
				ma = arr[i];
		}
		for (int i = 0; i < 26; ++i) {
			if(arr[i] == ma){
				char c = i + 'a';
				cout<< c;
			}
		}
		cout<<endl;
	}
	return 0;
}
