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
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int n2, n3, n5, n6;
int main() {
	file();
	cin >> n2 >> n3 >> n5 >> n6;
	ll num = min(n2 , min(n5 , n6));
	n2 -= num;
	ll num2 = min(n2 , n3);
	ll ans = 256 *  num + num2 * 32;
	cout<<ans<<endl;
	return 0;
}
