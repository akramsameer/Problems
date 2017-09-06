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
int n, a, b;
int main() {
	file();
	cin >> n >> a >> b;
	int cur = a;
	if (b < 0) {
		b *= -1;
		b = b % n;

		while (b--) {
			cur--;
			if (cur == 0)
				cur = n;
		}
	} else {
		b = b % n;
		while (b--) {
			cur++;
			if (cur == n + 1)
				cur = 1;
		}
	}
	cout << cur << endl;
	return 0;
}
