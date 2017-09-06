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
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int line = 0, n, t;
char arr[11][11];
bool valid(int i, int j, char c) {
	for (int k = 0; k < 4; k++) {
		int x = i + xdir[k];
		int y = j + ydir[k];

		if (x < 0 || x >= n || y < 0 || y >= n)
			continue;
		if (arr[x][y] == c)
			return false;
	}
	return true;
}
int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> arr[i][j];

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < 25; k++) {
					char c = 'A' + k;
					if (arr[i][j] == '.' && valid(i, j, c))
						arr[i][j] = c;

				}
			}
		printf("Case %d:\n", ++line);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				printf("%c", arr[i][j]);
			printf("\n");
		}
	}
	return 0;
}
