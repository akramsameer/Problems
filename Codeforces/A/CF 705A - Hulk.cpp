#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
#define isPowerOfTwo(S) (!(S & (S - 1)))
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
#endif
}
int t, n, arr[1000 + 9];
int main() {
	file();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if (i == n) {
			if (i & 1)
				cout << "I hate it";
			else
				cout << "I love it";
		} else {
			if (i & 1)
				cout << "I hate that ";
			else
				cout << "I love that ";
		}
	}
	cout << endl;
	return 0;
}
