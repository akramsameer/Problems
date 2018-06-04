//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
string str[3];
char vowel[] = { 'a', 'e', 'i', 'o', 'u' };
int main() {
	for (int i = 0; i < 3; ++i) {
		getline(cin, str[i]);
	}
	bool check = true;
	for (int i = 0; i < 3; ++i) {
		int ans = 0;
		for (int j = 0; j < str[i].size(); ++j) {

			for (int k = 0; k < 5; ++k) {
				if (str[i][j] == vowel[k])
					ans++;
			}
		}
		if (i % 2 == 0) {
			if (ans != 5) {
				check = false;
				break;
			}
		} else {
			if (ans != 7) {
				check = false;
				break;
			}
		}
	}

	if (check)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
