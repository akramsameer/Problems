#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
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
int ydir[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}

int main() {
	file();
	ll n, a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		ll w;
		cin >> w;
		ll x = (double) (w * a) / b;

		cout <<fixed<<setprecision(0)<< w - ceil(((double)x * b) / a) << " ";
	}
	cout<<"\n";
	return 0;
}

