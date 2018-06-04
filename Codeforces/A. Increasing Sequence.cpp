//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int arr[2001] , n , d ;
int main() {
	cin >>  n >> d;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	int count = 0 ;

	for (int i = 1; i < n; ++i) {
		if(arr[i] <= arr[i-1]){
			int ans = (arr[i-1] - arr[i])/d;
			ans++;
			arr[i] += ans * d;
			count += ans;
		}
	}

	cout << count<<endl;
	return 0;
}
