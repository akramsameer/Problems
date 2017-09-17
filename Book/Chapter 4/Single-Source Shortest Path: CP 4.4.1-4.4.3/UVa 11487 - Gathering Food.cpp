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
int xdir[] = { 1, -1, 0, 0 };;
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int n, x, y , tt = 1;
char arr[11][11];
bool valid(int xx, int yy, int i) {
	if (xx < 0 || xx >= n || yy < 0 || yy >= n
			|| (arr[xx][yy] != '.' && arr[xx][yy] - 'A' != i))
		return false;
	return 1;
}
int main() {
	file();
	while (cin >> n, n) {
		int m = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				if (isalpha(arr[i][j])) {
					m = max(m, (arr[i][j] - 'A'));
					if (arr[i][j] == 'A') {
						x = i;
						y = j;
					}
				}
			}

		int count = 1, min = 0;
		for (int i = 1; i <= m; i++) {
			int dist[11][11] { 0 }, path[11][11] { 0 };
			dist[x][y] = path[x][y] = 1;
			queue<ii> q;
			q.push(ii(x, y));
			arr[x][y] = '.';
			x = y = -1;
			while (sz(q)) {
				ii cur = q.front();
				q.pop();

				if (arr[cur.first][cur.second] - 'A' == i)
					x = cur.first, y = cur.second;

				for (int k = 0; k < 4; k++) {
					int nx = cur.first + xdir[k], ny = cur.second + ydir[k];
					if (valid(nx, ny, i)) {
						int & d = dist[nx][ny], &p = dist[nx][ny];
						if (!d) {
							d = dist[cur.first][cur.second] + 1, p =
									path[cur.first][cur.second];
							q.push(ii(nx, ny));
						} else if (d == dist[cur.first][cur.second] + 1)
							p  += path[cur.first][cur.second]%20437;
					}
				}
			}
			if (x == -1) {
				count = -1;
				break;
			}

			min = dist[x][y] - 1;
			count = (count * path[x][y]) % 20437;
		}
		if (count == -1)
					printf("Case %d: Impossible\n", tt++);
				else
					printf("Case %d: %d %d\n", tt++, min, count);
	}
	return 0;
}

