//============================================================================
// Name        : Working.cpp
// Author      : Akram
// Version     :
// Copyright   : Your copyright notice
// Description : Code c++
//============================================================================

#include <iostream>
#include <string>
using namespace std;
string pass , num[11] , ans;
int main() {
	getline(cin  , pass);
	for (int i = 0; i < 10; ++i) {
		getline(cin , num[i]);
	}
	for (int i = 0; i < 8; ++i) {
		string s = pass.substr(i*10 , 10);
		for (int j = 0; j < 10; ++j) {
			if(s == num[j])
				ans+=(j +'0');
		}
	}
	cout<<ans<<endl;
	return 0;
}
