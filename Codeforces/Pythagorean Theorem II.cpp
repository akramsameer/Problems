//============================================================================
// Name        : Pythagorean.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;
int n ;
int main() {
	cin >> n ;
	int count = 0;
	for (int a = 1; a <= n; ++a) {
		for (int b = a; b <= n; ++b) {
			int c = sqrt(a*a + b*b);
			if((a*a + b*b) == (c*c) && c <= n)
				count++;
		}
	}

	cout << count<<endl;
	return 0;
}
