//============================================================================
// Name        : To.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;
int ans = 0, x, y;
int main() {
	while (cin >> x >> y) {
		for (int i = 0; i < 32; i++)
			if ((x & (1 << i) )!= 0 ^ (y & (1 << i) )!= 0)
				ans |= (1 << i);
		cout << ans;
	}

	return 0;
}
