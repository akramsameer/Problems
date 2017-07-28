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
#define s second
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}

int n, d;
ii arr[100001];
ll r, l, sol, mx, ma , res = 0;
int main() {
	file();
	cin >> n >> d;

	int t = n;
	while (t--)
		scanf("%d%d", &arr[t].f, &arr[t].s);

	sort(arr, arr + n);


	l = r = sol = mx = 0;
	ma = 2 * d;
	while (r < n) {
		if (arr[r].first - arr[l].first < d) {
			mx += arr[r].second;
			r++;
		} else {
			mx -= arr[l].second;
			l++;
		}
		sol = max(sol, mx);
	}
	cout << sol << endl;
	return 0;
}

