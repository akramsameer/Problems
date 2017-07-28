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
struct edge {
	int u, v;
	double c;
	edge(int u, int v, double c) :
			u(u), v(v), c(c) {
	}
	bool operator <(const edge& e) const {
		return c > e.c;
	}
};
struct point{int x , y;};
struct UnionFind {
	vi parent, rank ;
	UnionFind(int n) {
		parent = vi(n + 1);
		rank = vi(n + 1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int find_set(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = find_set(parent[x]);
	}

	void link(int x, int y) {
		if (rank[x] > rank[y])
			swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y])
			rank[y]++;
	}

	bool union_set(int x, int y) {
		x = find_set(x);
		y = find_set(y);
		if (x != y)
			link(x, y);

		return x != y ;
	}
};

point arr[501];

double dist(point p1 , point p2){
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

pair<double , vector<edge> > MST (vector<edge> edgeList , int n , int rem){ // O(E logV)
	UnionFind uf(n);
	double mstCost = 0 ;
	priority_queue<edge> q ;
	for (int i = 0; i < edgeList.size(); ++i)
		q.push(edgeList[i]);

	while( !q.empty() && rem){
		edge e = q.top();	 q.pop();

		if(	uf.union_set(e.u , e.v) ){
			mstCost = e.c;
			rem--;
		}
	}


	return make_pair(mstCost , vector<edge>());

}

int main() {
	file();
	int t;
	const int MAXN = 100000;
	cin >> t;
	while (t--) {
		int s , n;
		cin >> s >> n ;
		for(int i = 0 ; i < n ; i++)
			cin >> arr[i].x >> arr[i].y;

		vector<edge> adjList;
		for(int i = 0 ; i < n ; i++)
			for(int j = i +1 ; j < n ;j++)
				adjList.push_back(edge(i , j , dist(arr[i] , arr[j])));

		cout<<fixed<<setprecision(2)<< MST(adjList , n , n-s).first <<endl;
	}
	return 0;
}

