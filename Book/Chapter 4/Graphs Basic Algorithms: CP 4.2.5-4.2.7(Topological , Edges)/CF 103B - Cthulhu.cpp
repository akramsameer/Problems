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
bool vis[101];
vi adj[101];
void dfs(int ind){
	vis[ind] = 1;
	for(int i = 0 ; i < sz(adj[ind]) ; i++){
		int to = adj[ind][i];
		if(!vis[to])
			dfs(to);
	}
}
int main() {
	file();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	bool ans = 1 && (n == m);
	for(int i= 1 ; i <= n ; i++){
		if(!vis[i])
			ans = false;
	}
	if(ans)
		printf("FHTAGN!\n");
	else
		printf("NO\n");
	return 0;
}
