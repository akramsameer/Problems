//============================================================================
// Name        : Nearly.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;
long long n ;
int main() {
	cin >> n ;
	int ans= 0;
	int len = 1 + floor(log(n));
	for(int i = 0 ; i <  len; i++){
		int d = n % 10 ;
		n/= 10;
		if(d== 4 || d == 7 )
			ans++;
	}
	if(ans == 4 || ans == 7)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
