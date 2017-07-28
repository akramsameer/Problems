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
int arr[2][400001];
int main() {
	freopen("in.txt", "r", stdin);
	int n ;
	cin >> n ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		int x , y ;
		cin >> x >> y ;
		ans += arr[0][x+y +200000];
		arr[0][x+y +200000]++;
		ans+= arr[1][x-y +200000];
		arr[1][x-y+200000]++;
	}
	cout<<ans<<endl;
	return 0;
}
