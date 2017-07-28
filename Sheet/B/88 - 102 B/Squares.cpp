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

int con[11][11][2] , ans[11];

int main() {
	file();
	int n, m, cas = 0;

	while (cin >> n >> m) {

		if (cas)
			puts("\n**********************************\n");
		printf("Problem #%d\n\n", ++cas);

		clr(con , 0);
		clr(ans , 0);
		for (int i = 0; i < m; i++) {
			char c;
			int x, y;
			cin >> c >> x >> y;
			if (c == 'H')
				con[x][y][0] = 1;
			else
				con[y][x][1] = 1;
		}

		for (int i = n; i > 0; i--) {
			for (int j = n; j > 0; j--) {
				if (con[i][j][0])
					con[i][j][0] = con[i][j + 1][0] + 1;
				if (con[i][j][1])
					con[i][j][1] = con[i+1][j][1] + 1;
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				for (int k = min(con[i][j][0], con[i][j][1]); k > 0; k--) {
					if (con[i + k][j][0] >= k && con[i][j + k][1] >= k)
						ans[k]++;
				}
			}
		}
		bool f = 0;
		for (int i = 1; i <= n; i++)
			if (ans[i])
				printf("%d square (s) of size %d\n", ans[i], i), f = 1;

		if (!f)
			printf("No completed squares can be found.\n");

	}

	return 0;
}

