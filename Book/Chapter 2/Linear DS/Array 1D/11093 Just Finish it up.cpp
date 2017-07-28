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
const int N = 100005;

int t, n, p[N], q[N], tc;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> p[i];
		for (int i = 0; i < n; ++i)
			cin >> q[i];
		ll sum = 0, mn = LLONG_MAX;
		for (int i = 0; i < n; ++i) {
			sum += p[i] - q[i];
			mn = min(mn, sum);
		}
		int index = 0;
		while (mn < 0 && index < n) {
			mn -= p[index] - q[index++];
		}
		cout << "Case " << ++tc << ": ";
		if (index == n || sum < 0)
			cout << "Not possible\n";
		else
			cout << "Possible from station " << index + 1 << "\n";
	}

	cout << flush;
}
