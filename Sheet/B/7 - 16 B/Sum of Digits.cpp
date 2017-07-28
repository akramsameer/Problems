#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
string str;
int n;
int main() {
	freopen("in.txt", "r", stdin);

	cin >> str;
	ll output = 0;
	int trans = 0;

	if (str.length() == 1) {
		cout << "0" << endl;
		return 0;
	}

	for (int i = 0; i <(int) str.length(); ++i) {
		int temp = str[i] - '0';
		output += temp;
	}
	trans++;

	while (output >= 10) {
		stringstream ss;
		ss << output;
		string s = ss.str();
		output = 0;

		for (int i = 0; i < (int) s.length(); ++i) {
			int temp = s[i] - '0';
			output += temp;
		}

		trans++;
	}
	cout << trans << endl;
	return 0;
}

