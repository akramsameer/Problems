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

int t, tots, n, m, xpos, ypos, grid[101][101];
bool vis[101][101];
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
struct node {
	int xpos, ypos, w;
	node(int xpos, int ypos, int w) :
			xpos(xpos), ypos(ypos), w(w) {
	}

	bool operator <(const node & e) const {
		return w > e.w;
	}
};
bool isvalid(int i, int j) {
	if (i <= 0 || i > n || j <= 0 || j > m)
		return false;
	return true;
}

int dijkstra() {
	priority_queue<node> q;
	memset(vis, 0, sizeof vis);
	q.push(node(1, 1, grid[1][1]));
	while (!q.empty()) {
		int i = q.top().xpos, j = q.top().ypos, cost = q.top().w;
		q.pop();
		if (i == xpos && j == ypos)
			return cost;
		for (int k = 0; k < 4; ++k) {
			int x = i + xdir[k], y = j + ydir[k];
			if (isvalid(x, y) && !vis[x][y]) {
				q.push(node(x, y, cost + grid[x][y]));
				vis[x][y] = 1;
			}
		}
	}
	return -1;
}
int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d%d\n", &n, &m);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				scanf("%d", &grid[i][j]);

		scanf("%d %d %d\n", &xpos, &ypos, &tots);
		int ans = dijkstra();
		if (tots - ans < 0 || ans == -1)
			printf("NO\n");
		else
			printf("YES\n%d\n", tots - ans);
	}
	return 0;
}
