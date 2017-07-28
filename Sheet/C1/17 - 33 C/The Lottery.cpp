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
ll lcm(ll a, ll b) {
	return (a * b) / __gcd(a, b);
}
int main() {
	file();
	ll n;
	int m;
	while (cin >> n >> m) {
		vector<ll> num = vector<ll>(m);

		for (int i = 0; i < m; i++)
			cin >> num[i];

		ll ans = 0;
		ll size = 1 << m;						// 2 ^ m probabilities
		for (int i = 1; i < size; i++) {
			vector<ll> temp;
			for (int j = 0; j < m; j++) {
				if (i & (1 << j))
					temp.push_back(num[j]);
			}

			ll g = temp[0];
			for (int j = 0; j < sz(temp); j++) {
				g = lcm(g, temp[j]);
			}

			if (sz(temp) & 1)
				ans += n / g;
			else
				ans -= n / g;

		}
		printf("%lld\n", n - ans);
	}
	return 0;
}

