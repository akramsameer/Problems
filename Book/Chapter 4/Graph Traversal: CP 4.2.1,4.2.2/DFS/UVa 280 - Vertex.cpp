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
int n, m;
vi adjList[100 + 9];
bool vis[100 + 9];
void dfs(int ind) {
	for (int i = 0; i < sz(adjList[ind]); i++) {
		int to = adjList[ind][i];
		if (!vis[to]) {
			vis[to] = 1;
			dfs(to);
		}
	}
}

int main() {
	file();
	while (cin >> n, n) {
		int u = -1, v = -1;
		while (cin >> u, u) {
			while (cin >> v, v)
				adjList[u].push_back(v);
		}

		cin >> m;
		int x;
		while (m--) {

			cin >> x;
			clr(vis, 0);
			dfs(x);
			vi ans;
			for (int i = 1; i <= n; i++)
				if (!vis[i])
					ans.push_back(i);
			printf("%d", sz(ans));
			for (int i = 0; i < sz(ans); i++)
				printf(" %d", ans[i]);
			printf("\n");

		}
		for (int i = 0; i < 100 + 9; i++)
			adjList[i].clear();

	}
	return 0;
}
