#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };

int arr[10001] , rem[10001] , n , m ;
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n ;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	for (int i = 0; i < n; ++i)
		rem[arr[i]] = i+1;

	cin >> m ;
	ll l = 0 , r =  0;
	for (int i = 0; i < m; ++i) {
		int temp ;
		cin >> temp;
		l += rem[temp];
		r += n - rem[temp] +1;
	}
	cout<< l <<" "<<r<<endl;
	return 0;
}

