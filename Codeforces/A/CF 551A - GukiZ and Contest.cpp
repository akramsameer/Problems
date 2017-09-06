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
int n , arr[2000 +9] , ans[2000 +9];
int main() {
	file();
	cin >> n ;
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i];

	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < n ; j++){
			if(i == j)
				continue;
			if(arr[i] < arr[j])
				ans[i]++;
		}
	cout<< ans[0] +1;
	for(int i = 1 ;i < n ; i++)
		cout<<" "<<ans[i] +1;
	return 0;
}
