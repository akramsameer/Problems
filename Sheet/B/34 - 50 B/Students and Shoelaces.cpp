#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
int n, m;
vi adj[101];
bool quit[101];
vi vec;


int bfs(int st) {
	bool vis[101];
	memset(vis, 0, sizeof vis);
	queue<int> q;
	q.push(st);
	int ret = 0;

	while (q.size()) {
		int cur = q.front();
		q.pop();
		vis[cur] = 1;
		int links = 0;
		for (int i = 0; i < (int) adj[cur].size(); i++) {
			int to = adj[cur][i];
			if (!quit[to]) {
				links++;
				if (!vis[to])
					q.push(to);
			}
		}
		if (links == 1) {
			ret++;
			vec.push_back(cur);
		}
	}



	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0 , res = 0;
	while (true) {
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			if (!quit[i]) {
				if (bfs(i)) {
					ans++;

				}
			}

		}
		for (int i = 0; i < vec.size(); ++i) {
				quit[vec[i]] = 1;
		}


		if(ans)
			res++;
		else
			break;
	}
	cout << res << endl;
	return 0;
}
