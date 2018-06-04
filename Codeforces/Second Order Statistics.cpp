//============================================================================
// Name        : Second.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;
int n , arr[101];
int main() {
	int i , ans = -1 ;
	cin >> n ;
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr , arr+n);
	for (i = 1; i < n; ++i) {
		if(arr[i] > arr[0]){
			ans = i ;
			break;
		}
	}

	if(ans == -1)
		cout<<"NO" <<endl;
	else
		cout << arr[ans]<<endl;
	return 0;
}
