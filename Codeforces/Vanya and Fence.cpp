//============================================================================
// Name        : Vanya.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
int n, h, arr[1000], i, sum;
int main() {
	sum = 0;
	cin >> n >> h;
	for (i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	for (i = 0; i < n; ++i) {
		if (arr[i] <= h)
			sum++;
		else
			sum = sum + 2;
	}

	cout<<sum<<endl;
	return 0;
}
