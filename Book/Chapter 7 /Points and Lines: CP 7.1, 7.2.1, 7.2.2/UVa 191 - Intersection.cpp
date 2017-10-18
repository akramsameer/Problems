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
	SegmentLine() {
	}

};
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
	cin >> n;
	while (n--) {
		int x, y, x1, y1, xleft, ytop, xright, ybottom;
		cin >> x >> y >> x1 >> y1 >> xleft >> ytop >> xright >> ybottom;
		SegmentLine seg = SegmentLine(point(x, y), point(x1, y1));
		line curl;
		pointsToLine(seg.st, seg.en, curl);
		// 4 seg
		SegmentLine rec[4];
		rec[0] = SegmentLine(point(xleft, ybottom), point(xleft, ytop));
		rec[1] = SegmentLine(point(xleft, ybottom), point(xright, ybottom));
		rec[2] = SegmentLine(point(xleft, ytop), point(xright, ytop));
		rec[3] = SegmentLine(point(xright, ybottom), point(xright, ytop));
		if (between(point(xleft, ytop), point(xright, ybottom), seg.st)
				|| between(point(xleft, ytop), point(xright, ybottom),
						seg.st))
			printf("T\n");
		else {
			bool f = 0;
			for (int i = 0; i < 4 && !f; i++) {
				SegmentLine& nxt = rec[i];
				line nxtl;
				pointsToLine(nxt.st, nxt.en, nxtl);

				if (areParallel(curl, nxtl)) {
					if (isSame(curl, nxtl)) {
						if (between(seg.st, seg.en, nxt.st)
								|| between(seg.st, seg.en, nxt.en)
								|| between(nxt.st, nxt.en, seg.st), between(
								nxt.st, nxt.en, seg.en)) {
							f = 1;
						}
					}
				} else {
					point c;
					areIntersect(curl, nxtl, c);
					if (between(nxt.st, nxt.en, c)
							&& between(seg.st, seg.en, c))
						f = 1;
				}
			}
			if (f)
				cout << "T" << endl;
			else
				printf("F\n");

		}

	}

	return 0;
}

