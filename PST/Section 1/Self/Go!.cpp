//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
char grid[10][10];
bool visw[9][9], visb[9][9] ;
int xdir[] = { 1, -1, 0, 0 },b, w;
int ydir[] = { 0, 0, 1, -1 };
void solve(int i, int j, char c) {
	if (i < 0 || i >= 9 || j < 0 || j >= 9
			|| ((c == 'X' && (grid[i][j] == 'O'|| visb[i][j])) ? true : false)
			|| ((c == 'O' && (grid[i][j] == 'X' || visw[i][j])) ? true : false))
		return;
	if (c == 'X')
		visb[i][j] = 1;
	else if (c == 'O' )
		visw[i][j] = 1;
	for (int k = 0; k < 4; ++k) {
		solve(i + xdir[k], j + ydir[k], c);
	}

}
int main() {
	int cas;
	scanf("%d", &cas);
	//getchar();
	while (cas--) {
		w = b = 0;
		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j)
				cin >> grid[i][j];

		for (int i = 0; i < 9; ++i)
			for (int j = 0; j < 9; ++j) {
				if (grid[i][j] == 'X' && !(visb[i][j]))
					solve(i, j, 'X');
				else if (grid[i][j] == 'O' && !(visw[i][j]))
					solve(i, j, 'O');
			}

		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if(visb[i][j] && visw[i][j]){}
				else if(visb[i][j])
					b++;
				else if(visw[i][j])
					w++;
			}
		}
		printf("Black %d White %d\n", b , w);

	}
	return 0;
}
