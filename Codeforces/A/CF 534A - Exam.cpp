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
int n;
int main() {
	file();
	int n;
	cin >> n;
	if (n == 2)
		printf("1\n1");
	else if (n == 3)
		printf("2\n1 3\n");
	else {
		printf("%d\n", n);
		for (int i = 1; i <= n; i += 2)
			printf("%d ", i);
		for (int i = 2; i <= n; i += 2)
			printf("%d ", i);
	}
	return 0;
}

