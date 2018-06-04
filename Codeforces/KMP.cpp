//============================================================================
// Name        : KMP.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
struct KMP{
	int* prefixFunction(string s){
		int n = s.length();
		int* pi = new int[n];
		for (int i = 0 , j = 0; i < n ; ++i) {
			while(j > 0 && s[i] != s[j])
				j= pi[j-1];

			if(s[i] == s[j])
				++j;

			pi[i] = j ;
		}
		return pi;
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
};
