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
int n, m, xpos, ypos, num;
char mp[21][21], land, water;
bool vis[21][21], flag;
bool safe(int& x, int& y) {

	if (y >= m )
		y = 0;
	if (y < 0)
		y = m - 1;

	if (x >= n || x <0 ||mp[x][y] == water )
		return 0;

	return 1;
}

void flood(int x, int y) {
	vis[x][y] = 1;
	if (x == xpos && y == ypos)
		flag = 1;
	num++;
	for (int i = 0; i < 4; i++) {
		int nx = x + xdir[i];
		int ny = y + ydir[i];
		if (safe(nx, ny) && !vis[nx][ny]) {
			flood(nx, ny);
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	while (cin >> n >> m) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> mp[i][j];

		clr(vis , 0);
		cin >> xpos >> ypos;
		land = mp[xpos][ypos];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (mp[i][j] != land) {
					water = mp[i][j];

				}

		int res = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				if (safe(i, j) && !vis[i][j]) {
					num = 0;
					flood(i, j);
					if(flag){
						flag = 0;
						continue;
					}
					res = max(res, num);
				}
			}

		cout << res << endl;
	}
	return 0;
}
