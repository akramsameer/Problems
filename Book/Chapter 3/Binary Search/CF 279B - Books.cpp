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

int n;
ll t;
int arr[10000 + 9];
int main() {
	file();
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}

	int cnt = 0;
	for(int i = 0 ; i <  n; i++){
		int mid = 0, lo = i, hi = n , ans = -1;
		while(lo <= hi){
			mid = (lo + hi) / 2;
			int tot = arr[mid] - arr[i];
			if(tot <= t){
				ans = mid ;
				lo =mid + 1;
			}
			else
				hi = mid -1;
		}
		cnt = max(cnt , ans - i);
	}

	cout << cnt << endl;
	return 0;

}
