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
const double PI = acos(-1.0);
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int ydir[] = { 0, 1, -1, 1, -1, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
struct point {
	double x, y;
	point() {
		x = y = 0.0;
	}
	point(double _x, double _y) :
			x(_x), y(_y) {
	}
};
pair<double, double> v[100000 + 9];
int n;
double x1, x2, k, b;
int main() {
	file();
	scanf("%d %lf %lf" , &n , &x1 , &x2);
	for (int i = 0; i < n; i++) {
		scanf("%lf %lf" , &k , &b);
		v[i] = (make_pair(x1 * k + b, x2 * k + b));
	}
	sort(v, v + n);
	bool inter = 0;
	for (int i = 1; i < n && ! inter; i++) {
		if (v[i].second < v[i - 1].second)
			inter = 1;
	}
	printf( ((inter) ? "YES\n" : "NO\n")) ;
	return 0;
}

