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
ll n, m, f[20 + 9], c[20 + 9], lineCounter = 1;
int main() {
	file();
	scanf("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf("%lld %lld", &f[i], &c[i]);
	scanf("%lld", &m);
	while (m--) {
		ll v, t;
		scanf("%lld %lld", &v, &t);

		ll mi = OO;
		for (int i = 0; i < (1 << n); i++) {
			ll cost = 0, ft = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					cost += c[j];
					ft += f[j];
				}
			}

			if (ft * t >= v)
				if (cost < mi)
					mi = cost;
		}

		if (mi != OO)
			printf("Case %lld: %lld\n", lineCounter++, mi);
		else
			printf("Case %lld: IMPOSSIBLE\n", lineCounter++);
	}
	return 0;
}
