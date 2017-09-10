// hint ::
/*
 * count |SCCs| without incoming edge from a vertex outside the SCC
 *
 * */


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
int n, m, t, cnt, numSCC;
vi dfs_num, vis, low, S, SCC;
vector<vi> adj;

void targan(int u) {
	dfs_num[u] = low[u] = cnt++;
	S.push_back(u);
	vis[u] = 1;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (dfs_num[v] == UNVISITED)
			targan(v);
		if (vis[v])
			low[u] = min(low[u], low[v]);
	}
	if (low[u] == dfs_num[u]) {
		int v;
		while (1) {
			v = S.back(), S.pop_back(), vis[v] = 0, SCC[v] = numSCC;
			if (v == u)
				break;
		}
		numSCC++;
	}
}
int main() {
	file();
	cin >> t;
	while (t--) {
		cin >> n >> m;
		adj.assign(n + 1, vi());
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		low.assign(n + 1, 0), SCC.assign(n + 1, 0), dfs_num.assign(n + 1,
				UNVISITED), vis.assign(n + 1, 0), S.clear(), cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (dfs_num[i] == UNVISITED)
				targan(i);
		}
		vi root;
		root.assign(numSCC , 1);
		for(int i = 1 ; i<= n ;i++){
			for(int j = 0 ; j < sz(adj[i]);j++){
				int v = adj[i][j];
				if(SCC[i] != SCC[v]) 		// check if there are edge coming from vertex outside SCC
					root[SCC[v]] = 0;
			}
		}
		int ans = 0;
		for(int i = 0 ; i < sz(root); i++){
			if(root[i])
				ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

