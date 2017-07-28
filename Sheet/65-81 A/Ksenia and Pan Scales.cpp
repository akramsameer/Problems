//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#define ll long long
using namespace std;
string i , k,o;
string solve(string s1 ,string s2){
	int pos = 0 ;
	int n1 = s1.size() , n2 = s2.size();

	string a , b , ret;
	while(pos < k.size()){
		while( n1 <= n2 && pos < k.size() ){
			ret += k[pos];
			pos++ , n1++;
		}
		while(n2 < n1 && pos < k.size()){
			s2 += k[pos];
			pos++ , n2++;
		}
	}

	 ret += s1 ;
	 if(ret.size() == s2.size())
		 return ret	+'|'+ s2 ;
	 else
		 return "Impossible";
}
int main() {
	cin >> i ;
	cin >> k ;
	o = solve( i.substr(0,i.find('|')),i.substr(i.find('|')+1,i.size()-1));
	cout<<o<<endl;


	return 0;
}
