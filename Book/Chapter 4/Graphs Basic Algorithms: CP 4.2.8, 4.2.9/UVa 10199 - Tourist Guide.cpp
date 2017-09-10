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
int n, m,lineCounter = 1, dfs_num[101], children, root, low[101], parent[101], cnt;
vi adj[101];
map<int, string> its;
map<string, int> sti;
set<string> ans;
void clear() {
	for (int i = 0; i < 101; i++)
		adj[i].clear();
	clr(dfs_num, UNVISITED);
	clr(low, 0);
	clr(parent, UNVISITED);
	ans.clear();
	cnt = 0;
}
void findArticulationPoints(int u) {
	dfs_num[u] = low[u] = cnt++;
	for (int i = 0; i < sz(adj[u]); i++) {
		int v = adj[u][i];
		if (dfs_num[v] == UNVISITED) {
			parent[v] = u;

			if (u == root)
				children++;

			findArticulationPoints(v);

			if (dfs_num[u] <= low[v] and u != root)
				ans.insert(its[u]);

			low[u] = min(low[u], low[v]);
		} else if (v != parent[u])
			low[u] = min(dfs_num[v], low[u]);

	}
}
int main() {
	file();
	bool f = 1;
	while (cin >> n, n) {
		clear();
		for (int i = 0; i < n; i++) {
			string str;
			cin >> str;
			sti[str] = i;
			its[i] = str;
		}
		if(!f)
			printf("\n");
		f = 0;
		cin >> m;
		for (int i = 0; i < m; i++) {
			string a, b;
			cin >> a >> b;
			adj[sti[a]].push_back(sti[b]);
			adj[sti[b]].push_back(sti[a]);
		}

		for (int i = 0; i < n; i++) {
			if (dfs_num[i] == UNVISITED) {
				root = i;
				children = 0;
				findArticulationPoints(i);
				if (children > 1)
					ans.insert(its[i]);
			}
		}
		printf("City map #%d: %d camera(s) found\n" , lineCounter++ , sz(ans));
		for(set<string>::  iterator it = ans.begin() ; it != ans.end() ; it++ ){
			cout<<*it<<endl;
		}

	}
	return 0;
}
