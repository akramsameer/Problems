#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)((v).size()))
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
ll n, mem[1001];
ll solve(ll sum) {

	if (sum > n)
		return 0;

	if (sum == n)
		return 1;

	if (mem[sum] != -1)
		return mem[sum];

	ll ret = 0;
	for (int i = 1; i <= 4; i++) {
		int inc = (i == 4 || i == 1) ? 1 : i;
		mem[sum] = ret = ret + solve(sum + inc);
	}

	return ret;
}
int main() {
	freopen("in.txt", "r", stdin);

	while (cin >> n) {
		clr(mem, -1);
		ll res = solve(0);

		cout << res << endl;
	}

	return 0;
}
