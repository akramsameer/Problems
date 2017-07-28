#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi adjList[10001];
int n, m, par[10001] , cnt = 0;

bool dfs(int cur, int parent) {
	if (par[cur] != -1)
		return false;
	par[cur] = parent;
	cnt++;
	bool ret = true;
	for (int i = 0; i < (int) adjList[cur].size(); ++i) {
		int v = adjList[cur][i];
		if (parent != v)
			ret = ret && dfs(v, cur);
	}
	return ret;
}
int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	memset(par, -1, sizeof par);
	bool froot = false;
	int root=1;
	for (int i = 0; i < m; ++i) {
		int s, e;
		scanf("%d %d\n", &s, &e);
		if (!froot) {
			root = s;
			froot = true;
		}
		adjList[s].push_back(e);
		adjList[e].push_back(s);
	}
	bool ans;
	if (n - 1 != m)
		ans = false;
	else
		ans = dfs(root, -2);

	if (ans && (cnt == n))
		printf("YES");
	else
		printf("NO");
	printf("\n");

	return 0;
}
