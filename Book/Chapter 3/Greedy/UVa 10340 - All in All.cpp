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

int main() {
	string s, t;
	int i=0 , j=0;
	while (cin >> s >> t ) {
		while(i < s.size() && j < t.size()){
			if(s[i] != t[j])
				j++;
			else
				i++ , j++ ;
		}
		if(i == s.size())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
