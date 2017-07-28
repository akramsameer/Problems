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
#define f first
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}

ll mod = 1000000007;
ll pw(ll x, ll a) {
	if (!a)
		return 1;
	ll ret = pw(x, a / 2);
	ret = (ret * ret) % mod;
	if (a & 1)
		ret = (ret * x) % mod;
	return ret;
}

int main() {
	file();
	ll n;
	cin >> n;
	if(!n)
	cout<<"1"<<endl;
	else
	cout << (pw(2, n - 1) * (pw(2, n) + 1)) % mod <<endl;
	return 0;
}

