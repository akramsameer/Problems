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
string h , s ;
int f[300];
int main() {
	file();
	getline(cin , h);
	for(int i = 0 ; i < sz(h) ;i++)
		f[h[i]]++;
	getline(cin , s);
	bool yes = true;
	for(int i = 0 ; i < sz(s);i++){
		char cur = s[i];
		if(f[cur] > 0)
			f[cur]--;
		else
			yes = false;
	}
	if(yes)
		printf("YES\n");
	else
		printf("NO\n");

#ifndef ONLINE_JUDGE
	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
