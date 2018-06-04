//============================================================================
// Name        : Anton.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
#include <string>
using namespace std;
set<char> S ;
string str;
int main() {
	getline(cin , str);
	for (int i = 1; str[i] != '}'; ++i) {
		if(str[i] != ',' && str[i] != ' ')
			S.insert(str[i]);
	}
	int ans = 0;
	while(S.size()){
		S.erase(S.begin());
		ans++;
	}
	cout<< ans<<endl;
	return 0;
}
