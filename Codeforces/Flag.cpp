//============================================================================
// Name        : Flag.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int m, n;
char arr[101][101];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	bool ans = true;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if(i == n-1 && j == m-1)
				break;
			if (i == n - 1) {
				if (arr[i][j] != arr[i][j + 1]) {

					ans = false;
					break;
				}
			}
			else if (j == m - 1) {
				if (arr[i][j] == arr[i + 1][j]) {

					ans = false;
					break;
				}
			} else {
				if ((arr[i][j] == arr[i + 1][j])
						|| (arr[i][j] != arr[i][j + 1])) {
					ans = false;
					break;
				}
			}

		}
	cout << ((ans) ? "YES" : "NO") << endl;

	return 0;
}
