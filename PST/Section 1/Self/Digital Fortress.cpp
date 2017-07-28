//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <cmath>
#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
char grid[105][105];
int t ;
int main() {
	freopen("in.txt" , "r" , stdin);
	scanf("%d\n" , &t) ;
	while(t--){
		string temp ;
		getline(cin , temp);
		int n = temp.size();
		if(ceil(sqrt(n)) != floor(sqrt(n))){
			cout <<"INVALID\n";
			continue;
		}
		n = sqrt(n);
		int cnt = 0;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				grid[i][j] = temp[cnt++];

		string o;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				o += grid[j][i];

		cout << o <<"\n";
	}
	return 0;
}
