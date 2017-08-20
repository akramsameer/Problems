#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
#define isPowerOfTwo(S) (!(S & (S - 1)))
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
#define f first
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
}
ll res = OO;

int main() {
	file();
	ll d1, d2, d3;
	cin >> d1 >> d2 >> d3;
	res = min(res, d1 + d3 + d2);
	res = min(res, d1 + d3 + d3 + d1);
	res = min(res, d2 + d2 + d1 + d1);
	res = min(res, d2 + d3 + d3 + d2);
	cout<<res<<endl;
	return 0;
}
