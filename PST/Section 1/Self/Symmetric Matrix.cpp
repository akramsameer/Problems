//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll arr[101][101];
int n ;
bool solve(){
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if(arr[i][j] != arr[n - i -1][n - j -1])
				return false;
	return true;
}
int main() {
	bool sy = true;
	char cc;
	int t ;
	cin >> t;
	int cases = 1 ;
	while(t--){
		sy =true;
		cin >> cc >> cc >> n ;

		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				cin >> arr[i][j] ;
				if(arr[i][j] < 0)
					sy = false;
			}
		printf("Test #%d: ",cases++);
		if(!sy){
			printf("Non-symmetric.\n");
			continue;
		}

		sy = solve();
		if(sy)
			printf("Symmetric.\n");
		else
			printf("Non-symmetric.\n");
	}
	return 0;
}
