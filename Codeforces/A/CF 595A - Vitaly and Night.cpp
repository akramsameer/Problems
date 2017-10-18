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
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int n , m;
bool arr[300][300];
int main() {
	file();
	cin >> n >> m;
	for(int i = 0 ; i < n ; i++)
		for(int j = 0 ; j < 2 * m ; j++)
			cin >> arr[i][j];

	int ans = 0 ;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m*2 ;j +=2 ){
			if(arr[i][j] || arr[i][j+1])
				ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

