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
int n ;
ll sum , mi =OO  , x ;
int main() {
	file();
	cin >> n;
	for(int i = 0 ; i< n ; i++){
		cin>> x;
		sum += x;
		if(x < mi && (x&1))
			mi = x;
	}
	if((sum&1) && mi != OO)
		sum -= mi;

	cout<< sum<<endl;
	return 0;

}
