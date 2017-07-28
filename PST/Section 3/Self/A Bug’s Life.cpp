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
vi adjList[2001];
bool vis[2001];
short gen[2001];
int t, n, m;
bool dfs(int cur) {
	bool ans = true;
	vis[cur] = 1;
	for (int i = 0; i < (int) adjList[cur].size(); ++i) {
		int to = adjList[cur][i];
		if (gen[cur] == gen[to])
			return false;
		else if (gen[to] == 0) {
			gen[to] = - gen[cur];
			ans = ans and dfs(to);
		}
	}
	return ans;
}

void clear() {
	for (int i = 0; i <= n; i++) {
		adjList[i].clear();
		gen[i] = 0;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d\n", &t);
	int c = 1;
	while (t--) {
		scanf("%d%d\n", &n, &m);
		clear();
		for (int i = 0; i < m; ++i) {
			int u, v;
			scanf("%d%d\n", &u, &v);
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		printf("Scenario #%d:\n", c++);
		memset(vis, 0, sizeof vis);
		bool ans = true;
		for (int i = 1; i <= n; ++i) {
			if (gen[i] == 0) {
				gen[i] = 1;
				ans = ans and dfs(i);
			}

		}
		if (ans)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
	return 0;
}
