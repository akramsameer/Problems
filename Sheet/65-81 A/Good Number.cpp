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
#define ll long long
using namespace std;
int n , k , num[10];
string arr[101];
void clear(){
	for (int i = 0; i < 10; ++i) {
		num[i] = 0;
	}
}
bool isgood(int ind) {
	clear();
	for (int i = 0; i < arr[ind].size(); ++i) {
		int c = arr[ind][i] - '0';
		num[c]= 1;
	}
	for (int i = 0; i <= k; ++i)
		if (num[i] == 0)
			return false;
	return true;
}

int main() {
	cin >>  n >> k;
	int ans=0;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if(isgood(i))
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
