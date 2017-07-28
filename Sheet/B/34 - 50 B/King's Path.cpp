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
int xdir[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ydir[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
ll xs, ys, xe, ye;
int n;
map<pair<ll, ll>, bool> mp;

ll BFS() {
	queue<pair<pair<ll, ll>, ll> > q;
	q.push(make_pair(make_pair(xs, ys), 0));
	while (q.size()) {
		ll x = q.front().first.first, y = q.front().first.second;
		ll d = q.front().second;
		q.pop();
		if (x == xe && y == ye)
			return d;
		mp[make_pair(x, y)] = 0;
		for (int i = 0; i < 8; i++) {
			ll nx = x + xdir[i];
			ll ny = y + ydir[i];
			if (mp[make_pair(nx, ny)])
				q.push(make_pair(make_pair(nx, ny), d + 1));
		}
	}
	return -1;
}

int main() {
	file();
	cin >> xs >> ys >> xe >> ye;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll r, a, b;
		cin >> r >> a >> b;
		for (ll j = a; j <= b; j++)
			mp[make_pair(r, j)] = 1;
	}
	cout<< BFS()<<endl;
	return 0;
}

