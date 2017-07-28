#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
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
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}

struct union_find{
	static const int MAXN = 105;
	int par[MAXN];
	int rank[MAXN];

	void init(){
		clr(par , -1);
		for(int i = 0 ; i < MAXN ; i++)
			rank[i] = 1;
	}

	int root(int a){
		if(par[a] == -1)return a;
		return par[a] = root(par[a]);
	}

	void unite(int a , int b){
		a = root(a);
		b = root(b);
		if(a == b)return ;
		if(rank[a] < rank[b])swap(a , b);

		par[b] = a;
		rank[a] += rank[b];
	}

	bool same(int a , int b){
		return root(a) == root(b);
	}

}uf[105];

int n , m;

int main() {
	file();
	for(int i =0 ; i < 100 ; i++)
		uf[i].init();
	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int a , b , c;
		cin >> a >> b >> c ;
		a--; b--; c--;
		uf[c].unite(a , b);
	}
	int q ;
	cin >> q;
	for(int i = 0 ; i < q ;i++){
		int u , v ;
		cin >> u>>v ;
		u--;v--;
		int res = 0 ;

		for(int i = 0 ; i < 100 ; i++)
			if(uf[i].same(u , v))
				res++;

		cout<<res<<endl;
	}

	return 0;
}















