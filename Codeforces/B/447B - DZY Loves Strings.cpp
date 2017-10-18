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
string str;
int f[26] , x, ans;
int main() {
	file();
	cin >> str >> x;
	int mx = 0;
	for(int i = 0 ; i < 26 ;i++){
		cin >> f[i];
		mx = max(f[i] , mx);
	}
	for(int i = 0 ; i < sz(str) ;i++){
		ans += (i+1) * f[str[i] - 'a'];
	}
	for(int i = sz(str) +1 ; i <= x + sz(str) ; i++)
		ans += i * mx;
	cout<<ans<<endl;

#ifndef ONLINE_JUDGE
	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
