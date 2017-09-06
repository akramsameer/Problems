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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int n, m;
int color[100000 + 9];
set<int> arr[100000 + 9];
int main() {
	file();
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> color[i];

	int mx = 0, col = -1;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		int c1 = color[x], c2 = color[y];
		if (c1 != c2) {
			arr[c1].insert(c2);
			arr[c2].insert(c1);

			if (sz(arr[c1]) > mx) {
				mx = sz(arr[c1]);
				col = c1;
			} else if (sz(arr[c1]) == mx)
				col = min(c1, col);

			if (sz(arr[c2]) > mx) {
				mx = sz(arr[c2]);
				col = c2;
			} else if (sz(arr[c2]) == mx)
				col = min(c2, col);
		}
	}
	if (col != -1)
		cout << col << endl;
	else {
		int* x = min_element(color + 1, color + n + 1);
		cout << *x << endl;
	}
	return 0;
}
