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
char event[59];
int arr[59];
int cur[59];
string temp, str;
int cnt = 0;
bool can(double v) {
	double x = v;
	int leaks = 0;
	int curspeed = arr[0];
	for (int i = 1; i <= cnt; i++) {
		int dis = cur[i] - cur[i - 1];

		x -= dis * leaks * 1ll;
		x -= (dis * 1.0 * curspeed) / 100.0;

		if (x < 0.0)
			return false;

		if (event[i] == 'f')
			curspeed = arr[i];
		else if (event[i] == 'l')
			leaks++;
		else if (event[i] == 'G')
			x = v;
		else if (event[i] == 'M')
			leaks = 0;
		else if (event[i] == 'e')
			break;

		if (x < 0.0)
			return false;
	}
	return 1;
}
int main() {
	file();

	while (cin >> cur[0]) {
		cnt = 0;
		getline(cin, temp);
		istringstream ss(temp);
		ss >> str;
		if (str[0] == 'F') {
			ss >> str >> arr[0];
			if(arr[0] == 0)
				break;
			event[0] = 'f';
		} else if (str[0] == 'L') {
			ss >> arr[0];
			event[0] = 'l';
		} else if (str == "Gas")
			event[0] = 'G';
		else if (str[0] == 'M')
			event[0] = 'M';
		else
			event[0] = 'e';

		for (int i = 1; true; i++) {
			cnt = i;
			getline(cin, temp);
			istringstream sss(temp);
			sss >> cur[i] >> str;
			if (str[0] == 'F') {
				sss >> str >> arr[i];
				event[i] = 'f';
			} else if (str[0] == 'L') {
				event[i] = 'l';
			} else if (str == "Gas")
				event[i] = 'G';
			else if (str[0] == 'M')
				event[i] = 'M';
			else {
				event[i] = 'e';
				break;
			}
		}
		double mid = 0.0, lo = 0.0, hi = 100000000.0;
		while ((hi - lo) > EPS) {
			mid = lo + (hi - lo) / 2.0;
			if (can(mid))
				hi = mid;
			else
				lo = mid;
		}
		printf("%.3lf\n" , lo);
	}
	return 0;
}
