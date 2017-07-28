#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
ll n, k;
int solve(ll ind, ll ans) {
	if (ind < k)
		return solve(ind + pow(2, ans - 1) / 2, ans - 1);
	else if (ind > k)
		return solve(ind - pow(2, ans - 1) / 2, ans - 1);
	else
		return ans;
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> k;
	int ans = solve(pow(2, n - 1), n);

	cout<< ans<<endl;
	return 0;
}
