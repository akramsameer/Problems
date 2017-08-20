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
	//freopen("out.txt", "w", stdout);
#endif
}

int main() {
	file();
	char c;
	int b = 0, w = 0;
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++) {
			cin >> c;
			if (c != '.') {
				if (isupper(c)) {
					w += (c == 'Q') ? 9 : 0;
					w += (c == 'R') ? 5 : 0;
					w += (c == 'B') ? 3 : 0;
					w += (c == 'N') ? 3 : 0;
					w += (c == 'P') ? 1 : 0;
				} else {
					b += (c == 'q') ? 9 : 0;
					b += (c == 'r') ? 5 : 0;
					b += (c == 'b') ? 3 : 0;
					b += (c == 'n') ? 3 : 0;
					b += (c == 'p') ? 1 : 0;
				}
			}
		}
	if(w > b)
		printf("White\n");
	else if(b > w)
		printf("Black\n");
	else
		printf("Draw\n");
	return 0;
}
