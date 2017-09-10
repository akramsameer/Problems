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
int n, m, dfs_num[1001], dfs_low[1001], parent[1001], root, cnt, chld, kk = 1;
vi adj[1001];
bool road[1001][1001];

void Bridge(int u) {
	dfs_num[u] = dfs_low[u] = cnt++;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];

		if (dfs_num[v] == UNVISITED) {
			road[u][v] = 1;
			parent[v] = u;
			Bridge(v);
			if (dfs_low[v] > dfs_num[u])
				road[v][u] = 1;

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		} else if (parent[u] != v) {
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
			if (!road[v][u])
				road[u][v] = 1;
		}
	}
}
int main() {
	file();
	while (cin >> n >> m) {
		if (!n && !m)
			break;

		clr(dfs_num, UNVISITED);
		clr(dfs_low, 0);
		clr(road, 0);
		clr(parent , UNVISITED);
		cnt = 0 ;
		for (int i = 0; i < 1001; i++)
			adj[i].clear();

		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (dfs_num[i] == UNVISITED) {
				root = i, chld = 0;
				Bridge(i);
			}
		}

		cout << kk++ << "\n\n";
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (road[i][j])
					cout << i << " " << j << '\n';
		cout << "#\n";
	}
	return 0;
}
