//============================================================================
// Name        : A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
int t;
int pi[100000000];
string needle, S, newstr;
//struct KMP {
//	int * prefixFunction(string s) {
//		int n = s.length();
//		int* pi = new int[n];
//		for (int i = 1, j = 0; i < n; ++i) {
//			while (j > 0 && s[i] != s[j])
//				j = pi[j - 1];
//
//			if (s[i] == s[j])
//				++j;
//
//			pi[i] = j;
//		}
//		return pi;
//	}
//
//};

int main() {
	cin >> t;
	cin>> newstr;
	cin>>S;
	int cnt = newstr.length();
	newstr += "$";
	newstr += S;
	int n = newstr.length();

	for (int i = 1, j = 0; i < n; ++i) {
		while (j > 0 && newstr[i] != newstr[j])
			j = pi[j - 1];

		if (newstr[i] == newstr[j])
			++j;

		pi[i] = j;
	}
	bool check= true;
	for (int i = 0; i < n; i++)
		if (pi[i] == cnt) {
			check =false;
			int ind = i - cnt - 1;
			int corind = ind - cnt + 1;
			cout << corind << endl;
		}
	if(check )
		cout<<endl;

	return 0;
}
