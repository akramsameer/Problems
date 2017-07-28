#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
#define f first
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
map<char, int> mp;

string solve(string& str) {
	string ret;

	int prev = mp[str[0]];

	for (int i = 1; i < sz(str); i++) {
		if(prev != mp[str[i]]){
			if(prev != 0)
				ret.push_back(char(prev+'0'));
			prev = mp[str[i]];
		}
	}

	if(prev != 0)
		ret.push_back(char(prev+'0'));
	return ret;
}

int main() {
	file();
	mp['B'] = 1;
	mp['F'] = 1;
	mp['P'] = 1;
	mp['V'] = 1;

	mp['C'] = 2;
	mp['G'] = 2;
	mp['J'] = 2;
	mp['K'] = 2;
	mp['Q'] = 2;
	mp['S'] = 2;
	mp['X'] = 2;
	mp['Z'] = 2;

	mp['D'] = 3;
	mp['T'] = 3;

	mp['L'] = 4;

	mp['M'] = 5;
	mp['N'] = 5;

	mp['R'] = 6;

	mp['A'] = 0;
	mp['E'] = 0;
	mp['I'] = 0;
	mp['O'] = 0;
	mp['U'] = 0;
	mp['H'] = 0;
	mp['W'] = 0;
	mp['Y'] = 0;

	string str;
	while (cin >> str)
		cout << solve(str) << endl;

	return 0;
}

