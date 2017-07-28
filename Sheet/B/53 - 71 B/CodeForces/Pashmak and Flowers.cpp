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
ll n, ma = 0, mxf = 0, mi = OO, mif = 0, arr[200001], diff, ways;

int main() {
	//freopen("in.txt", "r", stdin);
	bool isequ = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (ma != 0 && ma != arr[i])
			isequ = 0;

		if (arr[i] == ma)
			mxf++;
		else {
			if (arr[i] > ma) {
				ma = arr[i];
				mxf = 1;
			}
		}

		if (arr[i] == mi)
			mif++;
		else {
			if (arr[i] < mi) {
				mi = min(arr[i], mi);
				mif = 1;
			}
		}
	}
	if (isequ) {
		ways = n * (n - 1) / 2;
		diff = 0;
	} else {
		ways = mif * mxf;
		diff = ma - mi;
	}
	cout << diff << " " << ways << endl;

}
