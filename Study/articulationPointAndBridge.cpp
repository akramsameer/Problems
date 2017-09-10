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
int dfs_num[100], rootChildren, dfs_parent[100], dfs_low[100], dfsRoot,
		dfsNumberCounter = 0;
vi adjList[100];
bool articulation_vertex[100];

void articulationPointAndBridge(int u) {
	dfs_num[u] = dfs_low[u] = dfsNumberCounter++;
	for (int i = 0; i < sz(adjList[u]); i++) {
		int v = adjList[u][i];

		if (dfs_num[v] == UNVISITED) {
			dfs_parent[v] = u;
			if (u == dfsRoot)
				rootChildren++;

			articulationPointAndBridge(v);

			if (dfs_low[v] >= dfs_num[u])
				articulation_vertex[u] = true;
			if (dfs_low[v] > dfs_num[u])
				printf("Edge (%d, %d) is a bridge\n", u, v);

			dfs_low[u] = min(dfs_low[v], dfs_low[u]);

		} else if (v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main() {
	file();
	return 0;
}
