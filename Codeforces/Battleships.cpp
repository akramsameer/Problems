//============================================================================
// Name        : Battleships.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
char grid[105][105];
bool vis[105][105];
int t, n , xr[] = {1 , -1 , 0 , 0} , yr[]={0,0,1,-1};
void dfs(int i, int j) {
	if(i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == '.' )
		return ;
	grid[i][j] = '.';

	for(int i = 0 ; i < 4 ; i++){
		dfs(i + xr[i] , j + yr[i]);
	}
}
int main() {
	cin >> t;
	int c = 1;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> grid[i][j];
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (grid[i][j] == 'x') {
					ans++;
					dfs(i, j);
				}
			}
		}
		cout << "Case " << c++ << ": " << ans << endl;
	}
	return 0;
}
