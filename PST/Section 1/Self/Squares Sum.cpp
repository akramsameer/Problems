//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int grid[11][11];
int main() {
	freopen("in.txt" , "r" , stdin);
	int c = 1 , n ;
	while(scanf("%d\n" , &n) && n){
		int ans = 0 ;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				cin >> grid[i][j];
		int x =(n > 1)? n/2 : 1 , pos = 0;
		if(n & 1 && n != 1)
			x++;
		printf("Case %d:",c++);

		while(x--){
			ans = 0;
			for (int i = pos; i < n-pos; ++i)
				ans += grid[pos][i];

			for (int i = 1 + pos ; i < n-1 - pos; ++i)
				ans += (grid[i][pos] + grid[i][n-pos-1]);

			for (int i = pos; i < n - pos; ++i) {
				ans += grid[n-pos-1][i];
			}
			if(pos == n - pos -1)
				ans = grid[pos][pos];
//			if(n == 1)
//				ans = grid[0][0];
			cout<< " "<<ans;
			pos++;

		}
		cout<<endl;
	}
	return 0;
}
