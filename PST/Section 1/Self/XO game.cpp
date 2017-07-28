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
char grid[3][3];
int t;
bool hasWin(char c) {

	if ((grid[0][0] == grid[1][1]) && (grid[1][1] == grid[2][2])
			&& grid[1][1] == c)
		return true;

	if ((grid[0][0] == grid[0][1]) && (grid[0][1] == grid[0][2])
			&& grid[0][1] == c)
		return true;

	if ((grid[1][0] == grid[1][1]) && (grid[1][1] == grid[1][2])
			&& grid[1][1] == c)
		return true;

	if ((grid[2][0] == grid[2][1]) && (grid[2][1] == grid[2][2])
			&& grid[2][1] == c)
		return true;

	if ((grid[0][0] == grid[1][0]) && (grid[1][0] == grid[2][0])
			&& grid[1][0] == c)
		return true;
	if ((grid[0][1] == grid[1][1]) && (grid[1][1] == grid[2][1])
			&& grid[1][1] == c)
		return true;
	if ((grid[0][2] == grid[1][2]) && (grid[1][2] == grid[2][2])
			&& grid[1][2] == c)
		return true;

	if ((grid[0][2] == grid[1][1]) && (grid[1][1] == grid[2][0])
			&& grid[1][1] == c)
		return true;

	return false;
}
int main() {
	//freopen("in.txt" , "r" , stdin);
	freopen("in.txt", "r", stdin);
	scanf("%d", &t);
	while (t--) {
		int x = 0, o = 0;
		for (int i = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j) {
				cin >> grid[i][j];
				if (grid[i][j] == 'X')
					x++;
				else if (grid[i][j] == 'O')
					o++;
			}
		bool check =false;

		if(x == o)
			check = ! hasWin('X');
		else if (x == (o+1))
			check = ! hasWin('O');

		if(check)
			cout <<"yes\n";
		else
			cout<<"no\n";
	}

	return 0;
}
