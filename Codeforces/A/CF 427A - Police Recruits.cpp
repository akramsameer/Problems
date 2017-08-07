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
#endif
}
int t ,ind, d , q , p , l[10000+9] , hi[10000+9] ;
string names[10000+9];
int main() {
	file();
	int n , x , num = 0 ,ans = 0 ;
	cin >> n;
	for(int i = 0 ; i < n ; i++){
		cin >> x ;
		if(x == -1 && num > 1)
			num--;
		else if(x == -1 && num == 0)
			ans++;
		else
			num += x;
	}
	cout<<ans<<endl;
	return 0;
}
