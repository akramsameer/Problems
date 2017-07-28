//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#define ll long long
using namespace std;
int r1, r2, c1, c2, d1, d2;

int main() {
	cin >> r1 >> r2;
	cin >> c1 >> c2;
	cin >> d1 >> d2;

	bool exist = false;
	int i, j, k, l;
	for (i = 1; i < 10; ++i) {
		for (j = 1; j < 10; ++j) {
			if(i == j)continue;
			for (k = 1; k < 10; ++k) {
				if(i == k || j == k)continue;
				for (l = 1; l < 10; ++l) {
					if(i == l || j == l || k == l)continue;
					if ((i + j == r1) && (i + k == c1) && (i + l == d1)
							&& (j + l == c2) && (j + k == d2)
							&& (k + l == r2)) {
						exist = true;
						break;
					}
				}
				if (exist)
					break;
			}
			if (exist)
				break;
		}
		if (exist)
			break;
	}
	if (exist)
		cout << i << " " << j << "\n" << k << " " << l << endl;
	else
		printf("-1");

	return 0;
}
