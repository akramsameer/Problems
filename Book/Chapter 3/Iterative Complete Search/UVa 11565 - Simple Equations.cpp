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

int main() {
	file();
	int t, A, B, C;
	cin >> t;
	while (t--) {
		cin >> A >> B >> C;

		bool sol = 0;
		for (int a = -100; a <= 100; a++)
			for (int b = -100; b <= 100; b++)
				for (int c = -100; c <= 100; c++)
					if (a != b && c != a && c != b && a + b + c == A
							&& a * b * c == B && a * a + b * b + c * c == C) {
						if (!sol)
							printf("%d %d %d\n", a, b, c), sol = 1;

					}
		if (!sol)
			printf("No solution.\n");
	}
	return 0;
}
