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

map<string, string > mp;
map<string, string > :: iterator it;

int main() {
	freopen("i.txt" , "wt", stdout);
	string temp ;

	// blank line string will be empty
	while(getline(cin , temp) && temp.empty()){
		stringstream ss(temp);
		string s1 , s2;
		ss >> s1 >> s2 ;
		mp[s2] = s1 ;
	}

	while(cin >> temp ){
		it = mp.find(temp);
		if(it == mp.end())
			cout<< "eh\n";
		else
			cout << it->second <<"\n";
	}
	return 0;
}


