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
int t, n, x, lineCounter = 1;
vi adjList[100 + 9];
bool vis[100 + 9], rech[100 + 9], v[100 + 9];

void dfs(int ind, int x) {
	if (ind == x)
		return;
	vis[ind] = 1;
	if (x == -1)
		rech[ind] = 1;

	else
		v[ind] = 1;

	for (int i = 0; i < sz(adjList[ind]); i++) {
		int to = adjList[ind][i];
		if (!vis[to] && ind != x)
			dfs(to, x);
	}
}

int main() {
	file();
	cin >> t;
	while (t--) {
		cin >> n;
		for(int i = 0 ; i < 100 +9 ; i++)
			adjList[i].clear();
		clr(rech , 0);
		clr(vis , 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> x;
				if (x)
					adjList[i].push_back(j);
			}

		dfs(0, -1);
		printf("Case %d:\n", lineCounter++);

		for (int i = 0 , k = 0; i < 2 * n + 1; i++) {
			if (i % 2 == 0) {
				printf("+");
				for (int i = 0; i < 2 * n - 1; i++)
					printf("-");
				printf("+\n");
			} else {
				clr(v, 0);
				clr(vis , 0);
				dfs(0, k++);
				printf("|");
				for (int j = 0; j < n; j++) {
					if (rech[j] && !v[j])
						printf("Y|");
					else
						printf("N|");
				}
				printf("\n");
			}
		}

	}
	return 0;
}
