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
	freopen("out.txt", "w", stdout);
#endif
}
int n , m  , x;
vi adj[1000000 +9];
int main() {
	file();
	while(cin >> n >> m	){
		for(int i = 0 ; i < 1000000+9 ; i++)
			adj[i].clear();
		for(int i = 0 ; i < n ; i++){
			cin >> x;
			adj[x].push_back(i+1);
		}

		for(int i = 0 ; i < m ; i++){
			int k , v ;
			cin >> k >> v;
			if(sz(adj[v]) < k)
				printf("0\n");
			else
				printf("%d\n" , adj[v][k - 1]);
		}
	}
	return 0;
}
