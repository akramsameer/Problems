#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
#define isPowerOfTwo(S) (!(S & (S - 1)))
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
#define f first
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
#endif
}

int n, ans , caseCounter = 1;
bool row[30], rd[30], ld[30];
char board[16][16];
void backtrack(int c) {
	if (c == n) {
		ans++;
		return;
	}
	for (int r = 0; r < n; r++) {
		if (board[r][c] != '*' && !row[r] && !rd[r + c] && !ld[r - c + n - 1]) {
			row[r] = rd[r + c] = ld[r - c + n - 1] = 1;
			backtrack(c + 1);
			row[r] = rd[r + c] = ld[r - c + n - 1] = 0;
		}
	}
}
int main() {
	file();
	while (cin >> n, n) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin>> board[i][j];
		ans = 0;
		clr(row, 0);
		clr(rd , 0);
		clr(ld , 0);

		backtrack(0);

		printf("Case %d: %d\n" ,caseCounter++, ans);
	}
	return 0;
}
