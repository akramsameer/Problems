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
int n ;
string arrs[101];
int arr[101][2];
int main() {
	bool exist = false;
	cin >> n ;
	for(int i = 0 ; i< n ; i++)
		cin >> arrs[i] >> arr[i][0] >> arr[i][1];
	for(int i = 0 ; i < n ; i++){
		if(arr[i][0] >= 2400 && arr[i][1] > arr[i][0])
			exist = true;
	}
	if(exist)
		cout << "YES"<<endl;
	else
		cout << "NO" <<endl;
	return 0;
}
