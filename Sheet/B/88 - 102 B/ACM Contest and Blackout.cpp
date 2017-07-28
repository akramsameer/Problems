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
	int u, v, c;
	edge(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	;
	bool operator <(const edge& e) const {
		return c > e.c;
	}
};

struct UnionFind {
	vi parent, rank;
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
		return x != y;
	}
};

vector<edge> graph;
int u = -1, v = -1;

pair<int, vector<edge> > MST(int n) {
	UnionFind uf(n);
	vector<edge> ans;
	int mstCost = 0;
	priority_queue<edge> q;

	for (int i = 0; i < sz(graph); i++) {
		if (graph[i].u == u && graph[i].v == v)
			continue;
		q.push(graph[i]);
	}

	while (!q.empty()) {
		edge cur = q.top();
		q.pop();
		if (uf.union_set(cur.u, cur.v)) {
			mstCost += cur.c;
			ans.push_back(cur);
		}
	}

	if (sz(ans) != n - 1)
		return make_pair(OOI, vector<edge>());

	return make_pair(mstCost, ans);
}

int main() {
	file();
	int t, n, m;
	cin >> t;
	while (t--) {
		u = -1;
		v = -1;
		graph.clear();
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int x, y, c;
			cin >> x >> y >> c;
			graph.push_back(edge(x, y, c));
		}

		int s1 = 0, s2 = OOI;
		pair<int, vector<edge> > pa = MST(n);

		s1 = pa.first;
		vector<edge> mstEdges = pa.second;
		for (int i = 0; i < sz(mstEdges); i++) {
			u = mstEdges[i].u;
			v = mstEdges[i].v;
			s2 = min(s2, MST(n).first);
		}
		cout << s1 << " " << s2 << endl;

	}
	return 0;
}

