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
int xdir[] = { 1, -1, 0, 0 };
;
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int mx = 0  , n , x , pre , cur;
int main() {
	file();
	cin >>n >>pre ;
	mx = 1;
	cur = 1;
	for(int i = 1 ; i < n ; i++){
		cin >> x ;
		if(x > pre)
			cur++;
		else
			cur = 1;
		pre =  x ;
		mx = max(mx , cur);
	}
	cout<<mx<<endl;
	return 0;
}

