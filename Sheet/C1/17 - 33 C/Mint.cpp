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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
int lcm(int a, int b) {
	return (a * b) / __gcd(a, b);
}
int coin[50 + 9];
int legs[10 + 9];
int main() {
	file();
	int n, t;
	while (cin >> n >> t) {
		if (!n && !t)
			break;

		for (int i = 0; i < n; i++)
			cin >> coin[i];

		for (int i = 0; i < t; i++)
			cin >> legs[i];

		for (int j = 0; j < t; j++) {
			int mi = OOI, mx = 0;
			for (int i1 = 0; i1 < n; i1++)
				for (int i2 = i1 + 1; i2 < n; i2++)
					for (int i3 = i2 + 1; i3 < n; i3++)
						for (int i4 = i3 + 1; i4 < n; i4++) {
							int x = lcm(coin[i1],
									lcm(coin[i2], lcm(coin[i3], coin[i4])));

							mx = max(mx, (legs[j] / x * x));
							int temp = (legs[j] % x) ? 1 : 0;
							mi = min(mi, (legs[j] / x + temp) * x);

						}
			printf("%d %d\n", mx, mi);
		}

	}

	return 0;
}

