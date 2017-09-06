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
int n, m, k, x , p;
bool vis[109], arr[109][109];
vi adjList[100 + 9];
void dfs(int ind) {
	vis[ind] = 1;
	for (int i = 0; i < sz(adjList[ind]); i++) {
		int to = adjList[ind][i];
		if (!vis[to])
			dfs(to);
	}
}
int main() {
	file();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if(!k)
			p++;
		for (int j = 0; j < k; j++) {
			cin >> x;
			arr[i][x] = 1;
		}
	}

	if(p == n){
		cout<< p <<endl;
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int l = 1; l < 101; l++) {
				if (arr[i][l] && arr[j][l]) {
					adjList[i].push_back(j);
					adjList[j].push_back(i);
					break;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!vis[i]) {
			dfs(i);
			ans++;
		}
	}
	cout << ans - 1 << endl;
	return 0;
}
