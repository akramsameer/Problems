//============================================================================
// Name        : Games.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int n , a[31] , h[31];
int main() {
	cin >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> a[i] >> h[i];

	int ans = 0;
	for(int i = 0 ; i < n ; i++ )
		 for(int j = 0 ; j < n ;j++)
			 if(j != i && a[i] == h[j])
				 ans++;

	cout << ans <<endl;
	return 0;
}
