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
int mem[1000 +9][109] , t , ans , n , p[1000 +9]  , g, w [1000 +9] , x;
int solve(int ind , int rem){
	if(ind >= n)
		return 0;
	int& ret = mem[ind][rem];
	if(ret != -1)return ret;
	ret = solve(ind + 1 , rem) ;
	if(rem - w[ind] >= 0)
		ret = max(ret , solve(ind +1 , rem - w[ind]) + p[ind]);
	return ret;
}
int main() {
	file();
	cin >> t ;
	while(t--){
		cin >> n;
		clr(mem , -1);
		ans = 0;
		for(int i = 0 ; i < n ; i++)
			cin>> p[i] >> w[i];
		cin >> g ;
		for(int i = 0 ; i < g ;i++){
			cin >> x;
			ans += solve(0 , x);
		}
		cout<<ans<<endl;
	}
	return 0;
}
