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
ll i,n,x,m,k,ans;
int main()
{
    cin >> n;
	x = n;
	while (x)
	{
		x /= 10;
		m++;
	}
	ans = n*m + m - 1;
	k = 1;
	for (i = 0; i < m-1; i++)
	{
		k *= 10;
		ans -=k;
	}
	cout << ans << endl;
	return 0;
}

