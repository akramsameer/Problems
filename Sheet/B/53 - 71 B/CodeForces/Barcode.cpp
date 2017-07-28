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
#define s second
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
int dots[1000 + 9], n, m, x, y, mem[1000 + 9][1000 + 9][2];

int solve(int ind = 0, int w = 0, bool c = 0) {

	if (ind == m) {
		if (w < x || w > y)
			return OOI;
		return 0;
	}

	int& ret = mem[ind][w][c];
	if (ret != -1)
		return ret;

	//make it dot
	int sol1 = OOI , sol2 = OOI;
	if (w == 0 || (c == 1 && w >= x) || (c == 0 && w + 1 <= y))
		sol1 = (n - dots[ind]) + solve(ind + 1, (c == 0) ? w + 1 : 1, 0);

	//make it hash

	if (w == 0 || (c == 0 && w >= x) || (c == 1 && w + 1 <= y))
		sol2 = dots[ind] + solve(ind + 1, (c == 1) ? w + 1 : 1, 1);

	ret = min(sol1, sol2);
	return ret;
}

int main() {
	file();
	cin >> n >> m >> x >> y;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			if (c == '.')
				dots[j]++;
		}
	clr(mem, -1);
	cout << solve() << endl;
	return 0;
}

