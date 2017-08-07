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
	int n;
	bool fi = 1;
	while (cin >> n, n) {
		if (!fi)
			printf("\n");
		fi = 0;
		bool f = 0;
		for (int fghij = 1234; fghij <= 98765 / n; fghij++) {
			int abcde = fghij * n;
			int temp, used = (fghij < 10000);
			temp = abcde;
			while (temp) {
				used |= 1 << (temp % 10);
				temp /= 10;
			}
			temp = fghij;
			while (temp) {
				used |= 1 << (temp % 10);
				temp /= 10;
			}
			if (used == (1 << 10) - 1)
				printf("%0.5d / %0.5d = %d\n", abcde, fghij, n), f = 1;

		}
		if (!f)
			printf("There are no solutions for %d.\n", n);

	}
	return 0;
}
