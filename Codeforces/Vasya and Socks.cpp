//============================================================================
// Name        : Vasya.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int n , m ;
int main() {
	cin >> n >> m ;
	int ans = 0 ;
	while(n){

		n--;
		ans++;
		if(ans != 0 && ans % m == 0)
					n++;
	}
	cout<<ans<<endl;
	return 0;
}
