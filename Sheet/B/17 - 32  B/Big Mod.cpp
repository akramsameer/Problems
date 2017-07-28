#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
ll b, p, m;
ll solve(ll B, ll P) {
	if (P == 1)
		return B % m;
	if (P % 2)
		return ((B % m) * solve(B, P - 1)) % m;
	else {
		ll c = solve(B, P / 2);
		return ((c % m) * (c % m)) % m;
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	while (cin >> b >> p >> m) {
		ll res = solve(b, p);
		cout << res << endl;
		getchar();
	}

	return 0;
}
