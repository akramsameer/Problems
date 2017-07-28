//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;
ll st, en, i, j, k;
ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}
int main() {
	bool fail = false;
	cin >> st >> en;
	for (i = st; i <= en; ++i) {
		for (j = i+1; j <= en; ++j) {
			if (i == j)
				continue;
			for (k = j+1; k <= en; ++k) {
				if (i == k || j == k)
					continue;
				if (GCD(i, j) == 1 && GCD(j, k) == 1 && GCD(i, k) != 1) {
					fail = true;
					break;
				}
			}
			if (fail)
				break;
		}
		if (fail)
			break;
	}
	if (fail)
		cout << i << " " << j << " " << k << endl;
	else
		printf("-1\n");
	return 0;
}
