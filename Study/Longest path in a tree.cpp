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

int n , mx , e;
vi adjList[10001];
bool vis[10001];
void dfs(int cur , int cost){
	if(mx < cost){
		mx = cost;
		e = cur;
	}
	vis[cur] = 1 ;
	for (int i = 0; i <(int) adjList[cur].size(); ++i) {
		int to = adjList[cur][i];
		if(!vis[to])
			dfs(to , cost+1);
	}
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int s, e;
		cin >> s >> e;
		adjList[s].push_back(e);
		adjList[e].push_back(s);
	}
	dfs(1 , 0);
	mx = 0 ;
	memset(vis , 0 , sizeof vis);
	dfs(e , 0);
	printf("%d\n" , mx);
	return 0;
}
