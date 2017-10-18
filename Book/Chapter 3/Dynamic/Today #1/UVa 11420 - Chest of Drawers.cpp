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
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
ll n , s , mem[65][65][2] ;
ll solve(int ind , int num , bool sec){
	ll& ret = mem[ind][num][sec];
	if(ind == n ){
		if(num == s)
			return 1;
		return 0;
	}

	if(ret != -1)
			return ret;

	if(sec){
		ret = solve(ind + 1 , num +1 , 1) + solve(ind +1 , num , 0);
	}
	else
		ret = solve(ind +1 , num , 1) + solve(ind +1 , num , 0);
	return ret;

}
int main() {
	file();
	while(cin >> n >> s and n > 0){
		clr(mem  , -1);
		ll ans = solve(0 ,0, 1);
		printf("%lld\n" , ans);
	}
	return 0;
}

