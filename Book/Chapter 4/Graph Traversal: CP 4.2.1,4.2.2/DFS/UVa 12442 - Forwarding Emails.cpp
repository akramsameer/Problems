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
int t, n, lineCounter = 1, graph[50000 + 9], sum[50000 + 9], vis[50000 + 9];
int dfs(int ind) {
	vis[ind] = 1;
	int ret = 0, to = graph[ind];
	if (to != -1 && !vis[to])
		ret = 1 + dfs(to);
	vis[ind] = 0;
	return sum[ind] = ret;
}

int main() {
	file();
	cin >> t;
	while (t--) {
		clr(graph, -1);
		clr(sum, -1);
		cin >> n;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			graph[a] = b;
		}

		int ans = -1, mx_len = 0;
		for (int i = 1; i <= n; i++) {
			if (sum[i] == -1)
				dfs(i);
			if (sum[i] > mx_len) {
				mx_len = sum[i];
				ans = i;
			}
		}
		printf("Case %d: %d\n" , lineCounter++ , ans);

	}
	return 0;
}
