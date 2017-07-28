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
int const M = 18409900;
bool prime[M];
pair<ll, ll> ans[100001];
int cnt = 1;
int main() {
	file();
	ll k = 2;
	prime[0] = prime[1] = 1;
	for (ll i = 2; i <= M; i++) {
		while (i <= M && prime[i])
			i++;

		if (i - k == 2) {
			ans[cnt].first = k, ans[cnt].second = i;
			cnt++;
		}
		k = i;

		for (ll j = i * i; j <= M; j += i)
			prime[j] = 1;
	}

	ll n;
	while (cin >> n)
		printf("(%lld, %lld)\n", ans[n].first, ans[n].second);

	return 0;
}

