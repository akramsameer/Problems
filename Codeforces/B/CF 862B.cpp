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
const double PI = acos(-1.0);
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}

ll n;
ll c[3];
vi adj[100000 + 9];
bool vis[100000 + 9];
int color[100000 + 9];
void dfs(int ind, int pre) {
	vis[ind] = 1;
	color[ind] = color[pre] +1;
	c[color[ind] % 2]++;
	for(int i = 0 ; i < sz(adj[ind]);i++)
		if(!vis[adj[ind][i]])
			dfs(adj[ind][i] , ind);
}
int main() {
	file();
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1 , 0);
	cout<< (c[0] * c[1] - (n-1))<<endl;
	return 0;
}

