#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };

bool solve(ll x, ll y) {

	if (x < y)
		swap(x, y);

	if (y == 0)
		return false;

	bool win = false;


	win |= !solve(y, x % y);

	if (x/y != 1 && !win)
		win |= !solve(y, x % y + y);

	return win;
}

int main() {
	freopen("in.txt", "r", stdin);
	ll x, y;
	while (cin >> x >> y) {
		if (!x && !y)
			break;

		bool stanWin = solve(x, y);

		if (stanWin)
			cout << "Stan wins" << endl;
		else
			cout << "Ollie wins" << endl;
	}

	return 0;
}
