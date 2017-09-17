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
vii adj[100 + 9];
vi dist;
int t, n, e, k , m,cas = 1, s, en;
void dijkestra(){
	priority_queue<ii , vii , greater<ii> > pq;
	pq.push(ii(0 , e));
	dist[e] = 0;
	while(sz(pq)){
		ii front = pq.top();
		pq.pop();
		int u = front.second ;
		int d = front.first;
		if(d > dist[u])continue;
		for(int i = 0 ; i < sz(adj[u]);i++){
			ii v = adj[u][i];
			if(dist[u] + v.second < dist[v.first]){
				dist[v.first] = dist[u] + v.second;
				pq.push(ii(dist[v.first] , v.first));
			}
		}
	}
}
int main() {
	file();
	cin >> t ;
	while(t--){
		cin >> n >>e >> k >> m	;
		dist = vi(n +1 , OOI);
		for(int i = 0 ; i < 100 + 9 ; i++)
			adj[i].clear();

		for(int i =  0 ; i < m; i++){
			int a , b , c;
			cin >> a >> b>>c;
			adj[b].push_back(ii(a , c));
		}
		dijkestra();
		int ans = 0;
		for(int i = 1 ; i <= n ; i++){
			if(dist[i] <= k)
				ans++;
		}
		printf("%d\n" , ans);
		if(t)
			printf("\n");
	}
	return 0;
}

