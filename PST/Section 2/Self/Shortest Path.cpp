#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const int oo = 1e7;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int t, n, r;
vector<ii> adjList[10001];
bool vis[10001];

int dijkstra(int src, int dest) {

	priority_queue<ii> q;
	q.push(ii(0, src));
	vis[src] = 1;
	while (!q.empty()) {
		int cur = q.top().second;
		int cos = - q.top().first;
		q.pop();

		vis[cur] = 1;

		if(cur == dest)
			return cos;

		for (int i = 0; i < (int) adjList[cur].size(); ++i) {
			int to = adjList[cur][i].first;
			int cost = adjList[cur][i].second;
			if (!vis[to]) {
				q.push(ii(-cos - cost , to));
			}
		}
	}

	return -1;
}
int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d\n", &t);
	bool first = true;
	while (t--) {
		map<string , int> mp ;
		if (first)
			first = false;
		else
			getchar();
		scanf("%d\n", &n);
		int ind = 1;
		for (int i = 0; i < n; ++i) {
			char temp[20];
			scanf("%s\n", &temp);
			mp[temp] = ind;
			int sz;
			scanf("%d\n", &sz);
			for (int j = 0; j < sz; ++j) {
				int s, w;
				scanf("%d %d\n", &s, &w);
				adjList[ind].push_back(ii(s , w));
			}
			ind++;
		}
		scanf("%d\n", &r);
		int ans = -1;
		for (int i = 0; i < r; ++i) {
			char temp[20], temp2[20];
			scanf("%s%s", &temp, &temp2);
			ans = dijkstra(mp[temp], mp[temp2]);
			printf("%d\n", ans);
		}

		memset(vis , 0 , sizeof vis);
	}
	return 0;
}
