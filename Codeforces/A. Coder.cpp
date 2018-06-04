//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int n ;
int main() {
	cin >> n ;
	if((n&1))
		cout<<((n*n/2)+1)<<endl;
	else
		cout<<((n*n/2))<<endl;

	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			if((((i&1) == 0) && ((j&1) == 0))||((i&1)&&(j&1)))
				cout<<"C";
			else
				cout<<".";
		}
		cout<<endl;
	}


	return 0;
}
