//============================================================================
// Name        : Working.cpp
// Author      : Akram
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
queue<int> q;
int main() {
	freopen("in.txt", "r", stdin);
	char arr[6][6];
	int x = 0 , y = 0;
	for(int i = 1 ; i <= 5 ; i++)
		for(int j = 1  ; j <= 5 ; j++){
			cin >> arr[i][j];
			if(arr[i][j] == '1')
				x = i , y = j;
		}
	cout<<(abs(3-x)+abs(3-y))<<endl;

	return 0;
}

