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
	double w;
	edge(int u, int v,double w) :
			u(u), v(v), w(w) {
	}
	const bool operator <(const edge& e) const {
		if(w == e.w){
			if(u == e.u)
				return v > e.v;
			return u>e.u;
		}
		return w > e.w;
	}
};

struct UnionFind {
	vi parent, rank;
	UnionFind(int n) {
		parent = vi(n + 1);
		rank = vi(n + 1);

		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			rank[i] = 1;
		}
	}

	int find_set(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = find_set(parent[x]);
	}

	void merge(int x, int y) {
		if (rank[x] < rank[y])
			parent[x] =y ;
		else if (rank[x]>rank[y])
			parent[y] = x;
		else{
			parent[y] = x;
			rank[x]++;
		}


	}

	bool union_sets(int x, int y) {
		x = find_set(x);
		y = find_set(y);
		if (x != y) {
			merge(x, y);
		}
		return x != y;
	}
};

ii nodes[752];
int main() {
	file();
	int t, n, m;
	cin >> t;
	while (t--) {
		getchar();
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> nodes[i].first >> nodes[i].second;

		cin >> m;
		UnionFind uf(n);

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			uf.merge(x, y);
		}
		priority_queue<edge> edges;
		for (int i = 1; i <= n; i++) {
			for (int j = i+1; j <= n; j++) {

				double x1 = nodes[i].first, x2 = nodes[j].first;
				double y1 = nodes[i].second, y2 = nodes[j].second;
				double dis = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
				edges.push(edge(i, j, dis));
			}
		}
		vector<edge> ans;
		bool flag = 0;
		int rem = n - m - 1;
		while (edges.size()) {
			edge cur = edges.top();
			edges.pop();
			//printf( "@ %d %d  %lf\n", cur.u, cur.v , cur.w );
			if (uf.union_sets(cur.u, cur.v)) {
				ans.push_back(cur);
				flag = 1;
				rem--;
			}
		}
		if (flag)
			for (int i = 0; i < sz(ans); i++) {
				cout << ans[i].u << ' ' << ans[i].v << endl;
			}
		else
			cout << "No new highways need" << endl;
	}

	return 0;
}

