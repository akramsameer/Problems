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
char grid[300+9][309] , dia[300 +9][300 +9];
int main() {
	file();
	cin >> n ;
	int posx = 0 , posy = 0;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ;j++)
			cin>> grid[i][j];
	char cen = grid[0][0];
	char c = grid[1][0];
	bool yes = true;
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < n  ;j++){
			if((i == j) or (i + j == n-1)){
				if(grid[i][j]!= cen)
					yes = false;
			}else
				if(grid[i][j] != c)
					yes = false;
		}


	if(yes and cen != c)
		printf("YES\n");
	else
		printf("NO\n");


#ifndef ONLINE_JUDGE
	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
