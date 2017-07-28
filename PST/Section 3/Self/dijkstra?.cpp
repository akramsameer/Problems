#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long oo = 1e12;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct edge {
	int from, to;ll w;
	edge(int from, int to, ll w) :
			from(from), to(to), w(w) {
	}

	bool operator <(const edge & e) const {
		return w > e.w;
	}
};
int n, m;
vector<edge> adjList[100009];
void printPath(vi& prev, int ind) {
	if (prev[ind] == -1) {
	} else
		printPath(prev, prev[ind]);
	if (ind != n)
		cout << ind << " ";
	else
		cout << ind << endl;
}

void dijkstra(int src, int dest = -1) { //O(E logV)

	vi prev(n + 5, 1e9);
	vector<long long> dist(n + 5, oo);

	dist[src] = 0;

	priority_queue<edge> q;
	q.push(edge(-1, src, 0));
	bool check = false;
	while (!q.empty()) {
		edge e = q.top();
		q.pop();

		if (e.w > dist[e.to])
			continue;

		prev[e.to] = e.from;

		if (e.to == dest)
			check = true;

		for (int i = 0; i < (int) adjList[e.to].size(); ++i) {
			edge ne = adjList[e.to][i];

			if (dist[ne.to] > ne.w + dist[ne.from]) {
				ne.w = dist[ne.to] = ne.w + dist[ne.from];
				q.push(ne);
			}
		}

	}
	if (check )
		printPath(prev, n);
	else
		cout << "-1\n";
	return;

}
int main() {
	//freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v, c;
		cin >> u >> v >> c;
		adjList[u].push_back(edge(u, v, c));
		adjList[v].push_back(edge(v, u, c));
	}
	dijkstra(1, n);
	return 0;
}
