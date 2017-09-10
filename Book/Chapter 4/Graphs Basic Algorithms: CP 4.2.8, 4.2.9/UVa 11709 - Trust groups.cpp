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
int n  , m  , ans ,dfs_num[1001] , low[1001] , cnt ;
map<string , int> mp;
vi adj[1001] , S;
bool vis[1001];
void clear(){
	for(int i = 0 ; i < 1001 ; i++)
		adj[i].clear();
	clr(vis , 0);
	clr(dfs_num , UNVISITED);
	clr(low , 0);
	mp.clear();
	S.clear();
	ans= 0;
}
void targan(int u){
	dfs_num[u] = low[u] = cnt++;
	vis[u] = 1;
	S.push_back(u);
	for(int i = 0 ; i < sz(adj[u]) ;i++){
		int v = adj[u][i];
		if(dfs_num[v] == UNVISITED)
			targan(v);
		if(vis[v])
			low[u] = min(low[u] , low[v]);
	}
	if(dfs_num[u] == low[u]){
		ans++;
		while(1	){
			int v = S.back(); S.pop_back();vis[v] = 0;
			if(u == v)
				break;
		}
	}
}
int main() {
	file();
	while(cin >> n >> m){
		if(!n && !m)
			break;
		clear();
		string temp , a , b;
		getchar();
		for(int i = 0 ; i < n ; i++){
			getline(cin  , temp);
			mp[temp] = i;
		}
		for(int i = 0 ; i < m ; i++){
			getline(cin , a);
			getline(cin , b);
			adj[mp[a]].push_back(mp[b]);
		}
		for(int i = 0 ; i < n ; i++)
			if(dfs_num[i] == UNVISITED)
				targan(i);
		cout<<ans<<endl;
	}
	return 0;
}
