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
int n, k, arr[10000 + 9];
bool can(double mid) {
	double rem = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > mid) {
			double x = arr[i] * 1.0 - mid;
			rem += (x - (x * (k * 1.0)) / 100.0);
		}
		else
			rem -= (mid - arr[i] * 1.0);
	}
	return rem >= 0.0;
}
int main() {
	file();
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	double mid = 0.0, lo = 0.0, hi = 1000.0;
	while ((hi - lo) > EPS) {
		mid = lo + (hi - lo) / 2.0;
		if (can(mid))
			lo = mid;
		else
			hi = mid;
	}
	printf("%.9lf" , lo);
	return 0;

}
