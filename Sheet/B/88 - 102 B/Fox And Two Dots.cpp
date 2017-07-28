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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
int n, m;
char arr[51][51];
bool vis[51][51];

bool valid(int x , int y){
	if(x <  0 && x >= n && y < 0 && y >= m)
		return false;
	return 1;
}

bool dfs(int indx, int indy, int parx, int pary, char color) {
	if(vis[indx][indy])
		return 1;
	vis[indx][indy] = 1;
	bool ret = false;
	for (int i = 0; i < 4; i++) {
		int x = indx + xdir[i];
		int y = indy + ydir[i];

		if(valid(x , y) && !(x == parx && y == pary) && arr[x][y] == color)
			ret =ret || dfs(x , y , indx , indy , color);
	}
	return ret;
}

bool solve() {
	bool res = false;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!vis[i][j])
				res = res || dfs(i, j, -1, -1, arr[i][j]);
	return res;
}

int main() {
	file();
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	bool res = solve();
	if(res)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

