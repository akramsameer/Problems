#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };

int p , q, l , r ;
ii X[51] , Z[51];
bool valid (ii xx , ii yy){
	if(xx.second < yy.first || yy.second < xx.first)
		return false;
	return true;
}

int solve(){
	int ret = 0 ;
	for(int sh = l ; sh <= r ;sh++){
		for(int i = 0 ; i< p ;i++){
			bool flag = 0 ;
			for(int j = 0 ; j < q ; j++){
				ii newx ;
				newx.first = X[j].first + sh ;
				newx.second = X[j].second + sh;
				if(valid(newx , Z[i])){
					ret++;
					flag = 1 ;
					break;
				}
			}
			if(flag)
				break;
		}
	}
	return ret ;

}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> p >> q >> l >> r ;

	for(int i = 0 ; i < p ; i++)
		cin>> Z[i].first >> Z[i].second;

	for(int i = 0 ; i < q ; i++)
		cin >> X[i].first >> X[i].second;

	int res = solve();
	cout<<res<<endl;
	return 0;
}
