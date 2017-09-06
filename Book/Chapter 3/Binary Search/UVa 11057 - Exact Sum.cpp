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
const int N = 1e4 + 9;
int n  , arr[N] , m ;
int main() {
	file();
	while(cin >> n ){
		for(int i = 0 ; i < n ; i++)
			cin>> arr[i];
		sort(arr , arr + n);
		cin >> m;
		int x = 0 , y = 1e9;
		for(int i = 0 ; i < n ; i++){
			if(arr[i] > m)
				continue;

			int tar = m - arr[i];
			int ind  = lower_bound(arr+i+1 , arr + n , tar) - arr ;
			if(arr[ind] == tar){
				if(abs(x - y) > abs(arr[i] - tar)){
					x = min(arr[i], tar);
					y = max(arr[i], tar);
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n" , x , y);
	}
	return 0;
}
