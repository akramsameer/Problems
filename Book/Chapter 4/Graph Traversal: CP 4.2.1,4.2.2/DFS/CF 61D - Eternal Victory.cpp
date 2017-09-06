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
int n;
vii adj[100000 + 9];
bool vis[100000 + 9];

ll dfs(int ind) {
	vis[ind] = 1;
	ll ret = 0;
	for (int i = 0; i < sz(adj[ind]); i++) {
		int to = adj[ind][i].first;
		int w = adj[ind][i].second;
		if (!vis[to])
			ret = max(ret, dfs(to) + (ll) w);
	}
	return ret;
}

int main() {
	file();
	cin >> n;
	ll res = 0;
	for (int i = 0; i < n - 1; i++) {
		int x, y, w;
		cin >> x >> y >> w;

		adj[x].push_back(ii(y, w));
		adj[y].push_back(ii(x, w));
		res += 2 * w;
	}
	cout << res - dfs(1) << endl;
	return 0;
}
