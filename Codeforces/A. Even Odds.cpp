//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#define ll long long
using namespace std;
ll n, k, c;
int main() {
	cin >> n >> k;

	if (n & 1) {
		c = (n / 2 + 1);

	} else {
		c = n / 2 ;
	}
	if( k <= c){
		cout<<(k*2)-1 <<endl;
	}
	else
		cout<<(k-c)*2<<endl;

}
