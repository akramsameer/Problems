//============================================================================
// Name        : Die.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int y , w , d;
int main() {
	cin >> y >> w ;
	d =6 - max ( y , w );
	d++;
	int base = 6;

	for(int i = 6 ; i > 1 ; i--){
		if(d % i == 0 && base % i ==0 ){
			base /= i;
			d /= i;
		}
	}
	cout << d << "/" << base<<endl;
	return 0;
}
