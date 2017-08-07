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
//	freopen("out.txt", "w", stdout);
#endif
}
int k, board[8][8], mx;
bool rw[8], ld[30], rd[30];
void backtrack(int c, int sum) {
	if (c == 8) {
		if (sum > mx)
			mx = sum;
	}
	for (int r = 0; r < 8; r++) {
		if (!rw[r] && !rd[r + c] && !ld[r - c + 7]) {
			rw[r] = rd[r+c] = ld[r-c +7] = 1;
			backtrack(c +1 , sum + board[r][c]);
			rw[r] = rd[r+c] = ld[r-c +7] = 0;
		}
	}
}

int main() {
	file();
	scanf("%d", &k);
	while (k--) {
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				cin >> board[i][j];
		clr(rw, 0);
		clr(ld, 0);
		clr(rd, 0);
		mx = 0;
		backtrack(0, 0);
		printf("%5d\n" , mx);
	}
	return 0;
}
