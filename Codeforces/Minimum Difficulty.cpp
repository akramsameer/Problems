//============================================================================
// Name        : Working.cpp
// Author      : Akram
// Version     :
// Copyright   : Your copyright notice
// Description : Code c++
//============================================================================

#include <iostream>
#include <string>
#include <climits>
using namespace std;
int arr[1001] , n  , m , ans=1e9;
int main() {
	cin >> n ;
	cin>>arr[0];
	for (int i = 1; i < n; ++i) {
		cin >> arr[i];
		m = max(m , arr[i]-arr[i-1]);
	}
	for (int i = 2; i < n; ++i) {
		int temp = max(m , (arr[i]-arr[i-2]));
		ans = min (temp , ans);
	}
	cout<<ans<<endl;
	return 0;
}
