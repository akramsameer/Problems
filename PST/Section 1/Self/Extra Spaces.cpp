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

int main() {
	int t, kk = 1, n, sl;
	cin >> t;
	string s;
	while (t--) {
		cin >> n;
		getchar();
		if (kk != 1)
			cout << endl;
		cout << "Case " << kk++ << ":" << endl;

		for (int i = 0; i < n; i++) {
			getline(cin, s);
			sl = s.length();
			bool notc = true;
			for (int j = 0; j < s.size(); ++j) {
				if (s[j] == ' ' && notc) {
					cout << s[j];
					notc = false;
				} else if (s[j] != ' ') {
					cout << s[j];
					notc = true;
				}
			}
			cout << endl;
		}
	}
	return 0;
}
