#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
#define EPS 1e-9
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
const double PI = acos(-1.0);
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int n, tc, k, arr[10000 + 9], mem[10000 + 9][100 + 9];
bool solve(int ind, int val) {
	if (ind == n) {
		if ((val % k ) == 0)
			return 1;
		else
			return 0;
	}
	int& ret = mem[ind][val];
	if (ret != -1)
		return ret;
	ret = solve(ind + 1, (val + arr[ind]) % k)
			|| solve(ind + 1, ((val - arr[ind]) % k ));

	return ret;
}
int main() {
	file();
	cin >> tc;
	while (tc--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		clr(mem , -1);
		bool ans = solve(1, arr[0] % k);

		if (ans)
			printf("Divisible\n");
		else
			printf("Not divisible\n");
	}
	return 0;
}

