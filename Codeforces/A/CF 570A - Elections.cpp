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
ll n, m, arr[100 + 9];
int main() {
	file();
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		ll mx = 0, x;
		int ind = 0;
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x > mx) {
				mx = x;
				ind = j;
			}
		}
		arr[ind]++;
	}
	int  ind = -1 ;
	ll mx = 0;
	for(int i = 0 ; i < n ; i++){
		if(arr[i] > mx)
		{
			mx = arr[i];
			ind = i;
		}

	}
	cout<<ind +1<<endl;

	return 0;

}
