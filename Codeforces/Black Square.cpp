//============================================================================
// Name        : Black.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>

using namespace std;
int arr[4];
string str;
int main() {
	int i = 0 , cnt =0;
	for(i = 0 ; i < 4 ; i++)
		cin>> arr[i];
	cin>>str;

	for(i = 0 ; i < str.length(); i++){
		int a= str[i] - '0';
		a--;
		cnt += arr[a];
	}
	cout << cnt << endl;
	return 0;
}
