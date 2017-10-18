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
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
struct point {
	double x, y;
	point() {
		x = y = 0;
	}
	point(int _x, int _y) :
			x(_x), y(_y) {
	}
	bool operator <(point other) {
		if (fabs(x - other.x) > EPS)
			return x < other.x;
		else
			return y < other.y;
	}
};

vector<point> arr;
double dist(point p1, point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
struct line {
	double a, b, c;
};

// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
	if (fabs(p1.x - p2.x) < EPS) { // vertical line is fine
		l.a = 1.0;
		l.b = 0.0;
		l.c = -p1.x; // default values
	} else {
		l.a = -(double) (p1.y - p2.y) / (p1.x - p2.x);
		l.b = 1.0; // IMPORTANT: we fix the value of b to 1.0
		l.c = -(double) (l.a * p1.x) - p1.y;
	}
}

bool areParallel(line l1, line l2) { // check coefficients a & b
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

// returns true (+ intersection point) if two lines are intersect
bool areIntersect(line l1, line l2, point &p) {
	if (areParallel(l1, l2))
		return false; // no intersection
	// solve system of 2 linear algebraic equations with 2 unknowns
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// special case: test for vertical line to avoid division by zero
	if (fabs(l1.b) > EPS)
		p.y = -(l1.a * p.x + l1.c);
	else
		p.y = -(l2.a * p.x + l2.c);
	return true;
}

int t, n;
int main() {
	file();
	cin >> t;
	while (t--) {
		arr.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			double x, y;
			cin >> x >> y;
			arr.push_back(point(x, y));
		}
		sort(arr.begin(), arr.end());
		point pre = arr[n - 1];
		double ans = 0.0;
		for (int i = n - 2; i >= 0; i--) {
			point cur = arr[i];
			if (cur.y <= pre.y)
				continue;
			point c;
			line l1 , l2 ;
			pointsToLine(pre , point(0 , pre.y) , l1);
			pointsToLine(cur , arr[i+1] , l2);
			areIntersect(l1 , l2 , c);
			ans += dist(cur, c);
			pre = cur;
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}

