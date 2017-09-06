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
int n, x, c = 0, arr[2];
int main() {
	file();
	cin >> n;
	bool yes = 1;
	for (int i = 0; i < n; i++) {
		int x25 = 0, x50 = 0;
		cin >> x;
		switch (x -25) {
		case 75:
			x25 = 3;
			if (arr[1] > 0) {
				x25 = 1;
				x50 = 1;
			}
			break;
		case 25:
			x25 = 1;
			break;
		}
		arr[0] -= x25;
		arr[1] -= x50;

		if(arr[0] < 0)
			yes = 0;

		if(x== 25)
			arr[0]++;
		else if (x == 50)
			arr[1]++;

	}
	if (yes)
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}
