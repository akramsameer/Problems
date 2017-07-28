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

int parent[100];
int get_parent(int x){
	if(parent[x] != x)
		parent[x]= get_parent(parent[x]);

	return parent[x];
}


int main() {
	file();
	int n , m;
	cin >>  n >> m;
	for(int i = 0 ; i <= n;i++)parent[i] = i;
	for(int i = 0 ; i < m ; i++){
		int x , y;
		cin >> x >> y;
		parent[get_parent(x)] = get_parent(y);
	}
	ll ans = 1LL << n;

	for(int i = 1 ; i <= n ;i++){
		if(get_parent(i) == i)
			ans /= 2;
	}
	cout<<ans<<endl;
	return 0;
}
