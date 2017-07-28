//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <string.h>
#define ll long long
using namespace std;
int m, n, t;
vector<string> vec;
map<string, int> mp;
int main() {
	cin >> t;
	getchar();
	while (t--) {
		cin >> m >> n;
		for (int i = 0; i < m; ++i) {
			string s;
			int k;
			cin >> s >> k;
			mp[s] = k;
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			while (true) {
				string ss;
				cin >> ss;
				if (ss == ".")
					break;

				ans += mp[ss];

			}
			cout << ans << endl;
			ans = 0;
		}
	}
	return 0;
}
