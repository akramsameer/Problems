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
const int N = 1e6 + 9;
int n, m, arr[N];
bool can(int x){
	int ret = 1 , cur= 0;
	for(int i = 0 ; i < n ; i++){
		if(arr[i] > x)
			return false;

		if(cur + arr[i] <= x)
			cur += arr[i];
		else{
			ret++;
			cur = arr[i];
		}
	}
	return ret <= m;
}
int main() {
	file();
	while(cin >> n >> m){
		for(int i = 0 ; i < n ; i++)
			cin >> arr[i];
		int mid = 0 , lo = 0 , hi = 1e9 , ans = 0;
		while(lo <= hi){
			mid = lo + (hi - lo) / 2;
			if(can(mid)){
				hi = mid -1;
				ans = mid;
			}
			else
				lo = mid +1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
