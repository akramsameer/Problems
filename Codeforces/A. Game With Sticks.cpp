//============================================================================
// Name        : .cpp
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
	int ans = -1 ;
	while(n * m){
		ans *= -1 ;
		m --;
		n--;
	}
	if(ans == 1)
		cout<<"Akshat"<<endl;
	else
		cout<<"Malvika"<<endl;
	return 0;
}
