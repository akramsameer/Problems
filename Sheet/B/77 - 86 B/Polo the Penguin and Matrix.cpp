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
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}

int arr[10002] , n ,m  , d;
int main() {
	file();
	cin >> n >> m >> d;
	int cnt = 0;

	for(int i = 0 ; i < n ; i++)
		for(int j  = 0 ; j < m ; j++)
			cin >> arr[cnt++];

	sort(arr, arr+cnt);

	int mid = arr[cnt / 2];
	int ans = 0;
	for(int i = 0 ; i < cnt ; i++){
		int diff = abs(arr[i] - mid) ;
		if(diff % d == 0)
			ans += diff / d ;
		else{
			cout<<"-1"<<endl;
			return 0;
		}
	}
	cout<<ans<<endl;
	return 0;
}
