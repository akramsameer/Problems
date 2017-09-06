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
ll n ;
int k ;

int main() {
	file();
	cin >> n >> k;
	ll lo = 0 , ans = 0 , hi = 1e10;
	while(lo <= hi){
		ll mid = (lo + hi) / 2;
		ll kk= 1 , sum = 0;
		while(mid / kk > 0){
			sum += mid / kk;
			kk *= k;
		}

		if(sum >= n	){
			hi= mid -1 ;
			ans = mid;
		}
		else
			lo = mid +1;
	}
	cout<<ans<<endl;
	return 0;

}
