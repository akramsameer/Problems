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
	point(double _x, double _y) :
			x(_x), y(_y) {
	}
};
int cnt = 0;
struct SegmentLine {
	point st, en;
	int idx;
	SegmentLine(point _st, point _en) :
			st(_st), en(_en) {
		idx = cnt++;
	}

};
struct line {
	double a, b, c;
	line(){
		a = b = c = 0;
	}
	line(double _a, double _b, double _c) :
			a(_a), b(_b), c(_c) {
	}

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

bool areParallel(line l1, line l2) {
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool isSame(line l1, line l2) {
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}
bool between(point a, point b, point c) {
	return c.x <= max(a.x, b.x) + EPS && c.x + EPS >= min(a.x, b.x)
			&& c.y + EPS >= min(a.y, b.y) && c.y <= max(a.y, b.y);
}

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
int n;
int main() {
	file();
	point home, uni;
	cin >> home.x >> home.y >> uni.x >> uni.y;
	cin >> n;
	line l;
	int ans = 0;
	pointsToLine(home, uni, l);
	for (int i = 0; i < n; i++) {
		double a, b, c;
		point p ;
		line l2;
		cin >> a >> b >> c;
		if (b == 0)
			l2 = line(a, 0.0, c);
		else
			l2 = line(a / b, 1.0, c/b);
		if(areIntersect(l , l2 , p) && between(home , uni , p))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

