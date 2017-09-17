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
vii adj[20000 + 9];
int t, n, m, cas = 1, s, en;
int dij() {
	vi dist(n, OOI);
	dist[s] = 0;
	priority_queue<ii , vii , greater<ii> >pq;
	pq.push(ii(0 , s));
	while(sz(pq)){
		ii front = pq.top();
		pq.pop();
		int d = front.first  , u = front.second;
		if(d > dist[u])continue;
		for(int i = 0 ; i < sz(adj[u]);i++){
			ii v = adj[u][i];
			if(dist[v.second] > dist[u] + v.first){
				dist[v.second] = dist[u] + v.first;
				pq.push(ii(dist[v.second] , v.second));
			}
		}
	}
	return dist[en];
}
int main() {
	file();
	cin >> t;
	while (t--) {
		cin >> n >> m >> s >> en;
		for (int i = 0; i < m; i++) {
			int a, b, w;
			cin >> a >> b >> w;
			adj[a].push_back(ii(w, b));
			adj[b].push_back(ii(w, a));
		}
		int res = dij();
		if(res != OOI)
			printf("Case #%d: %d\n" , cas++ , res);
		else
			printf("Case #%d: unreachable\n", cas++);

		for(int i = 0 ; i < 20000+9;i++)
			adj[i].clear();
	}
	return 0;
}

