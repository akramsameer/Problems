//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
int n, arr[31][31];
bool solve(int i, int j) {
	int col = 0, row = 0;
	for (int k = 0; k < n; k++)
		col += arr[k][j];
	for (int k = 0; k < n; k++)
		row += arr[i][k];
	return col > row;
}
int main() {
	cin >> n;
	int ans = 0;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (solve(i, j))
				ans++;

	cout<<ans<<endl;
	return 0;
}
