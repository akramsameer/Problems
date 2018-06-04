//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;
char arr1[1001][501], arr2[1001][501];
bool vis1[1001], vis2[1001];
int n, m, cnt1 = 0, cnt2 = 0;
int main() {
	cin >> n >> m;
	int i;
	for (i = 0; i < n; i++) {
		cin >> arr1[i];
		vis1[i] = 1;
	}

	for (i = 0; i < m; i++) {
		cin >> arr2[i];
		vis2[i] = 1;
	}

	i = 0;
	int ind1 = 0;
	int ind2 = 0;
	while (i < n + m) {
		if (i % 2 == 0) {
			while (vis1[ind1] == 0 && ind1 < n) {
				ind1++;
			}
			string val = arr1[ind1];
			for (int j = 0; j < m; j++)
				if (val == arr2[j])
					vis2[j] = 0;
			ind1++;
		} else {
			while (vis2[ind2] == 0 && ind2 < m) {
				ind2++;
			}

			string val = arr2[ind2];
			for (int j = 0; j < n; j++)
				if (val == arr1[j])
					vis1[j] = 0;
			ind2++;
		}
		i++;
	}

	for (int j = 0; j < n; j++) {
		if (vis1[j])
			cnt1++;
	}
	for (int j = 0; j < m; j++) {
		if (vis2[j])
			cnt2++;
	}
	if (cnt1 > cnt2)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}
