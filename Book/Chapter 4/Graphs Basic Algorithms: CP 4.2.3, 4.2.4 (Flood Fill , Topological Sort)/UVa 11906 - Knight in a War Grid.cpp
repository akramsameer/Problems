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
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int t, lineCounter, r, c, n, m, w, ans[2];
bool water[105][105];
bool vis[105][105];

bool valid(int x, int y) {
	if (x >= 0 && x < r && y >= 0 && y < c)
		return 1;
	return 0;
}

void flood(int x, int y, int dx[], int dy[]) {
	vis[x][y] = 1;
	int ret = 0;
	for (int i = 0; i < 8; i++) {
		int xn = x + dx[i];
		int yn = y + dy[i];
		if (valid(xn, yn) && !water[xn][yn]) {
			ret++;
			if (!vis[xn][yn]) {
				flood(xn, yn, dx, dy);

			}
		}
	}
	ans[ret % 2]++;
}

int main() {
	file();
	cin >> t;
	while (t--) {
		clr(water, 0);
		clr(vis, 0);
		cin >> r >> c >> m >> n;
		int dx[] = { n, -n, -m, m, n, -n, m, -m };
		int dy[] = { m, -m, n, -n, -m, m, n, -n };
		cin >> w;
		while (w--) {
			int x, y;
			cin >> x >> y;
			water[x][y] = 1;
		}
		ans[0] = ans[1] = 0;
		flood(0, 0, dx, dy);
		printf("Case %d: %d %d\n", ++lineCounter, ans[0], ans[1]);
	}

	return 0;
}
