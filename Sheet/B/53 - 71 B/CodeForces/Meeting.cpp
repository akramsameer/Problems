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
struct circle {
	int x, y, r;
} arr[1001];
int xa, xb, ya, yb, n;

bool check(int x, int y) {
	for (int i = 0; i < n; i++)
		if (arr[i].r * arr[i].r
				>= (x - arr[i].x) * (x - arr[i].x)
						+ (y - arr[i].y) * (y - arr[i].y))
			return false;
	return true;
}

int main() {
	file();
	cin >> xa >> ya >> xb >> yb;
	if (xa > xb)
		swap(xa, xb);
	if (ya > yb)
		swap(ya, yb);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y >> arr[i].r;

	int ans = 0;
	for (int i = xa; i <= xb; i++) {
		if (check(i, ya))
			ans++;
		if (check(i, yb))
			ans++;
	}

	for (int i = ya +1 ; i < yb; i++) {
		if (check(xa, i))
			ans++;
		if (check(xb, i))
			ans++;
	}
	cout << ans << endl;
	return 0;
}
