//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> adjList[101];
int vis[101], n, m, cnt;

void dfs(int cur) {
	if (vis[cur])
		return;
	vis[cur] = 1;
	for (int i = 0; i < adjList[cur].size(); ++i)
		dfs(adjList[cur][i]);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	// flood fill
	int ans = 0;

	for (int i = 1; i <= n; ++i)
		if(!vis[i]){
			ans++;
			dfs(i);
		}


	cout << ans << endl;
	return 0;
}
