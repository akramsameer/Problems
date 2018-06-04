//============================================================================
// Name        : Adding.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int t;
string s1, s2;
int main() {
	cin >> t;
	char ans [201];
	int cnt=0;
	while (t--) {
		cin >> s1 >>s2;
		bool check = false;
		for (int i = 0, carry = 0; i < s1.size() || i < s2.size() || carry;i++) {
			ans[i] = carry + (((i < s1.size()) ? s1[i] : '0') - 48)
					+ (((i < s2.size()) ? s2[i] : '0') - 48);
			carry = 0;
			if (ans[i] >= 10) {
				carry = ans[i] / 10;
				ans[i] = ans[i] % 10;
			};
			ans[i] += 48;
			cnt++;

		}
		for (int i = 0; i < cnt; ++i) {
			if (ans[i] != '0' || check) {
				cout << ans[i];
				check = true;
			}
		}
	}
	return 0;
}
