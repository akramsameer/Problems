//============================================================================
// Name        : Cookies.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;
int n  , arr[101];
int main() {
	int i , sum=0  , ans= 0;
	cin >>  n ;

	for (i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	for (i = 0; i < n; ++i) {
		if((sum-arr[i])%2 == 0)
			ans++;
	}
	cout << ans;
	return 0;
}
