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
#define ll long long
using namespace std;

int n, k, arr[202];
int main() {
	cin >> n >> k;
	for (int i = 1; i <= 2 * n + 1; ++i) {
		cin >> arr[i];
	}
	int i = 2 * n;
	while (k) {
		if ((arr[i + 1]) < (arr[i] - 1) && (arr[i - 1] < (arr[i] - 1))) {
			arr[i]--;
			k--;
		}
		i -= 2;

	}
	for (int i = 1; i <= 2 * n + 1; ++i) {
		cout << arr[i] << " ";
	}
	return 0;
}
