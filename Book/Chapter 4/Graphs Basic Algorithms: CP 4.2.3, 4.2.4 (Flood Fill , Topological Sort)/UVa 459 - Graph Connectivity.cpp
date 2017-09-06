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
int t;
char lgst;
vi adjList[26];
bool vis[26];
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
	cin >> t;
	while (t--) {
		clr(vis, 0);
		for(int i = 0 ; i < 26 ; i++)
			adjList[i].clear();
		cin >> lgst;
		string temp;
		cin.ignore();
		while (getline(cin, temp) && sz(temp) != 0) {
			int from = temp[0] - 'A';
			int to = temp[1] - 'A';
			adjList[from].push_back(to);
			adjList[to].push_back(from);
		}
		int ans = 0;
		for (int i = 0; i <= lgst - 'A' ; i++) {
			if (!vis[i]) {
				dfs(i);
				ans++;
			}
		}

		cout << ans << endl;
		if (t)
			printf("\n");
	}
	return 0;
}
