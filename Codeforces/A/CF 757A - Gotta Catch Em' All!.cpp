#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
#define EPS 1e-9
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
string str;
map<char, int> mp;
int cnt[7];
int main() {
	file();
	mp['B'] = 0, mp['u'] = 1, mp['l'] = 2, mp['b'] = 3, mp['a'] = 4, mp['s'] = 5, mp['r'] = 6;
	cin >> str;
	for (int i = 0; i < sz(str); i++)
		cnt[mp[str[i]]]++;
	int mn = OOI;
	for (int i = 0; i < 7; i++)
		if (i == 1 || i == 4) {
			int x = cnt[i] / 2;
			mn = min(x, mn);
		} else
			mn = min(cnt[i], mn);
	cout << ((mn == 100)?106: mn ) <<endl;
	return 0;
}

