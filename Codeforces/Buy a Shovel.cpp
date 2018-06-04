//============================================================================
// Name        : Buy.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int k, r;
int main() {
	cin >> k >> r;
	for (int i = 1; true; i++) {
		int ans = k * i;

		if ((ans % 10) == 0 || (ans - r) % 10 == 0  ) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
