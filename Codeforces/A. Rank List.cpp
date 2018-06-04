//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
pair<int, int> arr[51];

bool cmp(pair<int, int> b, pair<int, int> a) {
	if (b.first >= a.first)
		return true;
	else if (b.first == a.first)
		if (b.second >= a.second)
			return true;
	return false;
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + n, cmp);
	pair<int, int> p = arr[k - 1];
	int c = 0;
	for (int i = 0; i < n; i++)
		if (arr[i].first == p.first && arr[i].second == p.second)
			c++;
	cout << c <<endl;

	return 0;
}
