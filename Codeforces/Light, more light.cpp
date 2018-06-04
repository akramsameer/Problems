//============================================================================
// Name        : Light,.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include <stdio.h>
#define ll long long
using namespace std;
ll x;
int main() {
	while (cin>>x , x) {
		if (floor(sqrt(x) == ceil(sqrt(x))))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
