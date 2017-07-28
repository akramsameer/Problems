//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool vis[502][502];
int h, w, n;
int main() {
	while (cin >> w >> h >> n, w) {
		while (n--) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			if (x1 > x2)
				swap(x1, x2);
			if (y1 > y2)
				swap(y1, y2);
			for (int i = x1; i <= x2; ++i) {
				for (int j = y2; j <= y2; ++j) {
					vis[i][j] = true;
				}
			}

		}
		int count = 0;
		for (int i = 1; i <= w; ++i) {
			for (int j = 1; j <= h; ++j) {
				if (!vis[i][j])
					count++;
				else
					vis[i][j] = 0;
			}
		}
		if (count == 0)
			cout << "There is no empty spots.\n";
		else if (count == 1)
			cout << "There is one empty spot.\n";
		else
			cout << "There are " << count << " empty spots.\n";
	}

	return 0;
}
