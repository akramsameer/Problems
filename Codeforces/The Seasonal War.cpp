//============================================================================
// Name        : The.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int xd[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int yd[] = { 0, 1, -1, 0, 1, -1, -1, 1 };
int n;
char grid[26][26];
void dfs(int i, int j) {
	if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == '0')
		return;
	grid[i][j] = '0';
	for (int k = 0; k < 8; k++)
		dfs(i + xd[k], j + yd[k]);
}
int main() {
	int C = 1;
	while (cin >> n) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == '1') {
					dfs(i, j);
					ans++;
				}

			}
		}

		cout << "Image number " << C++ << " contains " << ans << " war eagles."
				<< endl;


	}
	return 0;
}
