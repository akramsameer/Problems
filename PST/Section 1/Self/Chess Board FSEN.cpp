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
int grid[8][8];
bool diagonal(int i, int j) {
	int x1 = i + 1, y1 = j - 1, x2 = i + 1, y2 = j + 1;
	int x3 = i - 1, y3 = j - 1, x4 = i - 1, y4 = j + 1;
	while (x1 < 8 || y1 >= 0) {
		if (grid[x1][y1] == 'q' || grid[x1][y1] == 'b')
			return false;
		else if (grid[x1][y1] != '.')
			break;
		x1++, y1--;
	}
	while (x2 < 8 || y2 < 8) {
		if (grid[x2][y2] == 'q' || grid[x2][y2] == 'b')
			return false;
		else if (grid[x2][y2] != '.')
			break;
		x2++, y2++;
	}
	while (x3 >= 0 || y3 >= 0) {
		if (grid[x3][y3] == 'q' || grid[x3][y3] == 'b')
			return false;
		else if (grid[x3][y3] != '.')
			break;
		x3++, y3--;
	}
	while (x4 >= 0 || y4 < 0) {
		if (grid[x4][y4] == 'q' || grid[x4][y4] == 'b')
			return false;
		else if (grid[x4][y4] != '.')
			break;
		x4++, y4--;
	}

	return true;
}
bool straight(int i , int j ){}
bool save(int i, int j) {
	// Soldiers
	if (i > 0) {
		if (j > 0
				&& (grid[i - 1][j - 1] == 'p' || grid[i - 1][j - 1] == 'b'
						|| grid[i - 1][j - 1] == 'q'))
			return false;
		if (j < 8
				&& (grid[i - 1][j + 1] == 'p' || grid[i - 1][j + 1] == 'b'
						|| grid[i - 1][j - 1] == 'q'))
			return false;
	}
	// elephant and queen
	if(!diagonal(i , j))
		return false;

	// straight and queen
	if(!straight(i , j))
		return false;
}
int main() {
	//freopen("in.txt" , "r" , stdin);
	string temp;

	while (getline(cin, temp) && temp != "") {
		int posx = 7, posy = 0;
		for (int i = 0; i < temp.size(); ++i) {
			// if it digit
			if (temp[i] >= '0' && temp[i] <= '9') {
				int d = temp[i] - '0';
				for (int i = 0; i < d; ++i)
					grid[posx][posy++] = '.';
			} else if (temp[i] == '/') {
				posx--;
				posy = 0;
			} else
				grid[posx][posy++] = tolower(temp[i]);
		}
		int ans = 0;
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (grid[i][j] == '.') {
					if (save(i, j))
						ans++;
				}
			}
		}
		return 0;
	}
