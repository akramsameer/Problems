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
const int mx = 1e7 + 10;
ii arr[mx];
int cnt = 1;
int main() {
	file();
	for (int i = 1; i < mx and cnt < mx; i++) {
		for (int j = 1; j <= i and cnt < mx; j++) {
			if (i & 1)
				arr[cnt].first = i - j + 1, arr[cnt].second = j;
			else
				arr[cnt].first = j, arr[cnt].second = i - j + 1;
			cnt++;
		}
	}
	int x ;
	while(cin >> x)
		printf("TERM %d IS %d/%d\n", x, arr[x].first, arr[x].second);
	return 0;
}

