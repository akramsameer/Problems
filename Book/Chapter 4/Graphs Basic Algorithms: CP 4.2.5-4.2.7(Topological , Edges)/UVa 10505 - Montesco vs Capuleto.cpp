#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
#define EPS 1e-9
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
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int n, t, color[201];
vi adj[201];
bool isBib = 1;
bool has(int cur, int x) {
	for (int i = 0; i < sz(adj[cur]); i++) {
		int to = adj[cur][i];
		if (to == x)
			return 1;
	}
	return 0;
}

int solve(int st) {
	queue<int> q;
	color[st] = 0;
	int ret1 = 0, ret0 = 1;
	q.push(st);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < sz(adj[cur]); i++) {
			int to = adj[cur][i];
			if (color[to] == OOI) {
				color[to] = 1 - color[cur];
				if (color[to] == 0)
					ret0++;
				else
					ret1++;
				q.push(to);
			} else if (color[to] == color[cur]) {
				isBib = false;
			}
		}
	}
	return max(ret0, ret1);
}
int main() {
	file();
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < 201; i++)
			color[i] = OOI, adj[i].clear();
		for (int i = 1; i <= n; i++) {
			int p, x;
			cin >> p;
			for (int j = 0; j < p; j++) {
				cin >> x;
				if (x <= n) {
					if (!has(i, x))
						adj[i].push_back(x);
					if (!has(x, i))
						adj[x].push_back(i);
				}
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			isBib = 1;
			if (color[i] == OOI) {
				int x = solve(i);
				if (isBib)
					ans += x;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
