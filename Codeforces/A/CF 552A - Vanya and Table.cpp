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
int n ;
int table[100 +9][100 +9];
int main() {
	file();
	cin >> n ;
	while(n--){
		int x1 , x2 , y1 , y2 ;
		cin >> x1 >> y1 >> x2 >> y2;
		for(int i = min(x1 , x2) ; i <= max(x1 , x2);i++)
			for(int j = min(y1 , y2) ; j <= max(y1 , y2) ;j++)
				table[i][j]++;
	}
	int ans = 0 ;
	for(int i = 0 ; i < 100 +9 ; i++)
		for(int j = 0 ; j < 100 +9 ;j++)
			ans += table[i][j];
	printf("%d\n", ans);

#ifndef ONLINE_JUDGE
	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
