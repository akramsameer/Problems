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
int k , n , m ;
int arr[1002];
int diff(int temp){
	int ret = 0 ;
	while(temp){
		int rem = temp % 2 ;
		temp = temp / 2 ;
		if(rem)
			ret++;
	}
	return ret;
}
int main() {
	freopen("in.txt", "r", stdin);
	cin>> n >> m >> k ;
	for(int i = 0 ; i < m ; i++)
		cin >> arr[i];

	int f  = 0;
	cin >> f;
	int ans = 0;
	for(int i = 0 ; i < m ; i++){
		if(diff(f ^ arr[i]) <= k)
			ans++;
	}
	cout<<ans<<endl;
	return 0;
}
