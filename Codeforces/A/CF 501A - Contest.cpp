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
int xdir[] = { 1, -1, 0, 0 };
;
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int a, b, c, d;

int main() {
	file();
	cin >> a >> b >> c >> d;
	int p1 = max(3 * a / 10, a - ((a / 250) * c));
	int p2 = max(3 * b / 10, b - ((b / 250) * d));
	if(p1 > p2)
		printf("Misha\n");
	else if(p2 > p1)
		printf("Vasya\n");
	else
		printf("Tie\n");
	return 0;
}

