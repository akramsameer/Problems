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
const double PI = acos(-1.0);
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int ydir[] = { 0, 1, -1, 1, -1, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int x, f[26], n, m, r, c,vis, mx, mxcnt, tc, line = 1;
char cc;
int main() {
	file();
	cin >> tc;
	while (tc--) {
		cin >> r >> c >> m >> n;
		mx = mxcnt = vis =0 ;
		clr(f , 0);
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> cc;
				f[cc - 'A']++;
				if (f[cc - 'A'] == mx)
					mxcnt++;
				else if (f[cc - 'A'] > mx)
					mx = f[cc - 'A'], mxcnt = 1;

			}
		}
		printf("Case %d: %d\n", line++, mx*mxcnt * m + (r * c - mx * mxcnt) * n);
	}

	return 0;
}

