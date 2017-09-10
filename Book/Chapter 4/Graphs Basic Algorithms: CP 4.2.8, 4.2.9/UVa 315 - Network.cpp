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

int n  , dfs_num[101] ,dfsRoot , dfsNumberCounter, rootChildren ,dfs_low[101] , dfs_parent[101] ;
vi adj[101];
set<int> arc;

void articulationPointAndBridge(int u) {
	dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
	for(int i = 0 ; i < sz(adj[u]);i++){
		int v = adj[u][i];

		if(dfs_num[v] == UNVISITED){
			dfs_parent[v] = u ;

			if(u == dfsRoot)
				rootChildren++;

			articulationPointAndBridge(v);

			if(dfs_low[v] >= dfs_num[u] and u != dfsRoot)
				arc.insert(u);

			dfs_low[u] = min(dfs_low[u] , dfs_low[v]);
		}
		else if(dfs_parent[u] != v)
			dfs_low[u] = min(dfs_low[u] , dfs_num[v]);
	}
}

int main() {
	file();
	string line	;
	while(cin >> n  , n){
		clr(dfs_num , -1);
		clr(dfs_parent , -1);
		clr(dfs_low , 0);
		arc.clear();
		for(int i = 0 ; i < 101 ; i++)
			adj[i].clear();

		while(getline(cin  , line) and line[0] != '0'){
			stringstream ss(line);
			int u , v;
			ss >> u ;
			while(ss >> v){
				adj[u].push_back(v);
				adj[v].push_back(u);
			}
		}
		for(int i = 1 ; i <= n ; i++){
			if(dfs_num[i] == UNVISITED){
				dfsRoot = i;
				rootChildren = 0;
				articulationPointAndBridge(i);
				if(rootChildren > 1)
					arc.insert(i);
			}
		}

		printf("%d\n", sz(arc));
	}
	return 0;
}
