#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
#define f first
#define s second
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
int n, par[2000 + 9];
vi adjList[2000 + 9];
bool vis[2000 + 9];
int solve(int ind) {
	vis[ind] = 1;
	int ret = 0;
	for (int i = 0; i < sz(adjList[ind]); i++)
		ret = max(ret, solve(adjList[ind][i]) + 1);
	return ret;
}
int main() {
	file();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		par[i] = x;
		if (x != -1)
			adjList[x].push_back(i);
	}

	int res = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i] && par[i] == -1)
			res = max(res, solve(i) +1);

	cout<<res<<endl;
	return 0;
}

