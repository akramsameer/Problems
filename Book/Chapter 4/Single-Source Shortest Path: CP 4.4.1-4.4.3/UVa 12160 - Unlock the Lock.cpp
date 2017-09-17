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
string l, u, arr[11];

int r, cas = 1;
int conv(string str) {
	int ret = 0;
	for (int i = 0; i < 4; i++)
		ret = ret * 10 + (str[i] - '0');
	return ret;
}
int bfs() {
	queue<ii> q;
	vector<bool> vis(10000, 0);
	q.push(make_pair(conv(l), 0));
	vis[conv(l)] = 1;
	int dis = conv(u);
	while (sz(q)) {
		ii cur = q.front();
		q.pop();

		if (cur.first == dis)
			return cur.second;

		for (int i = 0; i < r; i++) {
			int ne = (cur.first + conv(arr[i])) % 10000;
			if (!vis[ne]) {
				vis[ne] = 1;
				q.push(ii(ne, cur.second + 1));
			}
		}

	}
	return -1;
}
int main() {
	file();
	while (cin >> l >> u >> r) {
		if (r == 0)
			break;
		for (int i = 0; i < r; i++)
			cin >> arr[i];
		int ans = bfs();
		if (ans == -1)
			printf("Case %d: Permanently Locked\n", cas++);
		else
			printf("Case %d: %d\n", cas++, ans);
	}
	return 0;
}

