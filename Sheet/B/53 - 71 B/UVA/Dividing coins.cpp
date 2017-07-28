#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
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
int ydir[] = { 0, 0, 1, -1 };
int t , n , sum , arr[100], mem[101][50001];
int solve(int ind , int k){
	if(ind >= n)
		return abs((sum - k) - k );
	int& ret = mem[ind][k];

	if(ret != -1)
		return ret ;

	ret = min(solve(ind+1 , k + arr[ind]) , solve(ind+1 , k));
	return ret;
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >>t ;
	while(t--){
		cin >> n ;
		sum = 0 ;
		clr(mem , -1);
		for(int i = 0 ; i < n ; i++){
			cin >> arr[i];
			sum += arr[i];
		}
		int res = solve(0 , 0);
		cout<<res<<endl;
	}

	return 0;
}
