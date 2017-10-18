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
string str;
map<string, pair<double, double> > mp;
struct point {
	double x, y;
	point() {
		x = y = 0.0;
	}
	point(double _x, double _y) :
			x(_x), y(_y) {
	}
	;
};
int tc = 1;
double dist(point p1, point p2) {
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p2.y - p1.y) * (p2.y - p1.y));
}
int main() {
	file();
	mp["N"] = make_pair(0, 1), mp["S"] = make_pair(0, -1), mp["E"] = make_pair(
			1, 0), mp["W"] = make_pair(-1, 0);
	mp["NE"] = make_pair(1 / sqrt(2),1/ sqrt(2)), mp["NW"] = make_pair(-1/sqrt(2), 1/sqrt(2)), mp["SW"] =
			make_pair(-1/sqrt(2), -1/sqrt(2)), mp["SE"] = make_pair(1/sqrt(2), -1/sqrt(2));

	while (getline(cin, str)) {
		if (str[0] == 'E' && str[1] == 'N' and str[2] == 'D')
			break;
		int steps = 0;
		point s = point();
		string key = "";
		for (int i = 0; i < sz(str); i++) {
			if (str[i] == ',' || str[i] == '.') {
				pair<double, double> cur = mp[key];
				s.x += steps * cur.first;
				s.y += steps * cur.second;
				key = "";
				steps = 0;
			} else if (isdigit(str[i]))
				steps = (steps * 10) + (str[i] - '0');
			else {
				key.push_back(str[i]);
			}
		}
		printf("Map #%d\n", tc++);
		printf("The treasure is located at (%.3lf,%.3lf).\n", s.x, s.y);
		printf("The distance to the treasure is %.3lf.\n\n", dist(point(), s));
	}
	return 0;
}

