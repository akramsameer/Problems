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


int main() {
	file();
	int x1, x2, y1, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int dx = abs(x1 - x2);
	if (abs(y1 - y2) != 0) {
		if (dx == 0)
			dx = abs(y1 - y2);
		else if (dx != abs(y1 - y2)) {
			cout << "-1\n";
			return 0;
		}
	}

	if (x1 == x2)
		cout << x1 + dx << " " << y1 << " " << x2 + dx << " " << y2 << endl;
	else if (y1 == y2)
		cout << x1 << " " << y1 - dx << " " << x2 << " " << y2 - dx << endl;
	else
		cout << x1 << " " << y1 + dx << " " << x2 << " " << y2 - dx << endl;
	return 0;
}
