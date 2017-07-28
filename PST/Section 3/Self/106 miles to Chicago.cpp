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

struct node {
	int to;
	double w;
	node(int to, double w) :
			to(to), w(w) {
	}

	bool operator <(const node & e) const {
		return w < e.w;
	}
};
int n, m;
vector<node> adjList[10001];
bool vis[101];
void clear() {
	for (int i = 0; i < n; i++)
		adjList[i].clear();
	memset(vis, 0, sizeof vis);
}
double dijkstra() {

	priority_queue<node> q;
	q.push(node(1, 1));
	while (!q.empty()) {
		int cur = q.top().to;
		double cost = q.top().w;
		q.pop();
		if (cur == n)
			return cost;
		vis[cur] = 1;
		for (int i = 0; i <(int) adjList[cur].size(); ++i) {
			node to = adjList[cur][i];
			if (!vis[to.to]) {
				q.push(node(to.to, cost * to.w));
			}
		}
	}
	return -1;
}
int main() {
	freopen("in.txt", "r", stdin);
	while (scanf("%d", &n)) {
		if (n == 0)
			break;
		scanf("%d\n", &m);
		clear();
		for (int i = 0; i < m; ++i) {
			int u, v, p;
			scanf("%d%d%d\n", &u, &v, &p);
			adjList[u].push_back(node(v, p / 100.0));
			adjList[v].push_back(node(u, p / 100.0));
		}
		double ans = dijkstra();
		//cout<<fixed<<setprecision(6)<<ans<<" percent"<<endl;
		printf("%.6lf percent\n", ans * 100.0 + 1e-10);
	}
	return 0;
}
