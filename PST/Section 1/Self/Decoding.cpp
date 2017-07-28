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
	int n, c = 1;
	string temp;
	cin >> n;
	while (c <= n) {
		cin >> temp ;
		string o ;
		int f=0 , k=0;
		char ch ;
		for (int i = 0; i < temp.size(); ++i) {
			if(temp[i] >='0'  && temp[i]<= '9'){
				k = temp[i] - '0';
				f = (f*10)+k;
			}
			else
			{
				if(f != 0){
					while(f--)o += ch;
					f = 0;
				}
				ch = temp[i];
			}
		}
		while(f--)o+=ch;
		cout<<"Case "<<c++ <<": "<< o <<endl;
	}
	return 0;
}
