#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vii adjList[50001];
bool vis[50001];
int n, t, cnt = 0, res, eInd;
void dfs(int cur, int cost) {
	if (res < cost){
		res = cost;
		eInd = cur;
	}
	vis[cur] = 1;
	for (int i = 0; i < (int) adjList[cur].size(); ++i) {
		ii v = adjList[cur][i];
		if (!vis[v.first])
		  dfs(v.first, cost + v.second);
	}
	vis[cur] = 0;
}
int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d\n", &t);
	while (t--) {
		scanf("%d\n", &n);
		for (int i = 0; i < n - 1; ++i) {
			int s, e, c;
			scanf("%d %d %d\n", &s, &e, &c);
			adjList[s].push_back(make_pair(e, c));
			adjList[e].push_back(make_pair(s, c));
		}
		res = 0 , eInd = 0;
		dfs(1, 0);
		res = 0 ;
		dfs(eInd , 0);
		printf("%d\n", res);
	}
	return 0;
}
