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
int h, w;
char grid[26][26];
bool vis[26][26];

bool valid(int i, int j) {
	if (i < 0 || i >= h || j < 0 || j >= w || grid[i][j] == 'X')
		return false;
	return true;
}

int dijkstra(ii s, ii e) {
	priority_queue<pair<int, ii> > q;
	q.push(make_pair(0, make_pair(s.first, s.second)));

	while (q.size()) {
		int curi = q.top().second.first;
		int curj = q.top().second.second;
		int cost = -q.top().first;
		q.pop();

		if (curi == e.first && curj == e.second)
			return cost;

		vis[curi][curj] = 1;

		for (int i = 0; i < 4; ++i) {
			int nexi = curi + xdir[i];
			int nexj = curj + ydir[i];
			if (valid(nexi, nexj) && !vis[nexi][nexj]) {
				if (grid[nexi][nexj] != 'D') {
					int c = grid[nexi][nexj] - '0';
					q.push(make_pair(-c - cost, make_pair(nexi, nexj)));
				}
				else
					q.push(make_pair(-cost , make_pair(nexi , nexj)));
			}
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	while (scanf("%d%d\n", &w, &h) && w && h) {
		ii s, e;

		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				scanf("%c", &grid[i][j]);
				vis[i][j] = false;
				if (grid[i][j] == 'S') {
					s.first = i;
					s.second = j;
				} else if (grid[i][j] == 'D') {
					e.first = i;
					e.second = j;
				}
			}
			getchar();
		}

		int ans = dijkstra(s, e);
		printf("%d\n", ans);

		getchar();
	}
	return 0;
}
