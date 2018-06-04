//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;
int n;
ll arr[100001];
int main() {
	int i ;
	cin >> n ;

	for (i = 0; i < n; ++i)
		cin >> arr[i];

	cout << arr[1] - arr[0] <<" "<< arr[n-1] - arr[0] <<endl;
	for(int i = 1 ; i < n-1 ; i ++){
		cout<< min(arr[i]-arr[i-1] , arr[i+1] - arr[i]) << " "<<
				max (arr[n-1]- arr[i] , arr[i]-arr[0])<<endl;
	}
	cout<< arr[n-1] - arr[n-2] << " "<<arr[n-1] - arr[0]<<endl;
}
