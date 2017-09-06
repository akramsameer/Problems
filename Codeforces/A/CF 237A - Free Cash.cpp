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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int n, curh, curm, mx = 0, ans = 1, preh, prem;
int main() {
	file();
	preh = prem = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> curh >> curm;
		if (curh == preh && curm == prem)
			ans++;
		else {
			mx = max(ans, mx);
			ans = 1;
		}
		preh = curh;
		prem = curm;
		mx = max(ans, mx);
	}

	cout << mx << endl;
	return 0;
}
