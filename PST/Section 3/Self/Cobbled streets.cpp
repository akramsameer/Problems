#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };

int t, p, nn, m;

int rankk[1001], parent[1001];
int forests;
struct edge {
	int from, to;ll w;

	edge(int from, int to, ll w) :
			from(from), to(to), w(w) {
	}

	bool operator <(const edge & e) const {
		return w > e.w;
	}
};

void intial(int n) {
	for (int i = 0; i < n; ++i){
		parent[i] = i;
		rankk[i] = 1;
	}
}

int find_set(int x) {
	if (x == parent[x])
		return x;
	return parent[x] = find_set(parent[x]);
}
void link(int x, int y) {
	if (rankk[x] > rankk[y])
		swap(x, y);
	parent[x] = y;
	if (rankk[x] == rankk[y])
		rankk[y]++;
}

bool union_sets(int x, int y) {
	x = find_set(x), y = find_set(y);
	if (x != y) {
		link(x, y);
		forests--;
	}
	return x != y;
}
priority_queue<edge> q;
ll kruskal(vector<edge> edges, int n) {
	intial(n);
	ll mstCost = 0;
	while (q.size())
		q.pop();

	for (int i = 0; i < (int) edges.size(); ++i)
		q.push(edges[i]);

	while (q.size()) {
		edge ee = q.top();
		q.pop();

		if (union_sets(ee.from, ee.to))
			mstCost += ee.w;

	}
	return mstCost;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--) {
		vector<edge> edgeList;
		cin >> p >> nn >> m;
		for (int i = 0; i < m; ++i) {
			int from, to;
			ll w;
			cin >> from >> to >> w;
			edgeList.push_back(edge(from, to, w));
		}
		ll totalW = kruskal(edgeList, nn);
		ll ans = totalW * p;
		cout << ans << endl;
	}
	return 0;
}
