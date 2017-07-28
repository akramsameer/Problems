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
#define f first
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
int t , n , p , arr[4001] ;

int main() {
	file();
	cin >> t ;
	while(t--){
		cin >> n ;
		cin >> p ;
		int ans = 0;
		bool vis[4000] = {0};
		while(p--){
			int x ;
			cin >> x ;
			int temp = x -1 ;
			while(temp < n){
				int d = temp % 7;
				if(d != 5 && d != 6 && !vis[temp]){
					ans++;
					vis[temp] = 1 ;
				}
				temp += x;
			}
		}

		cout<< ans<<endl;
	}


	return 0;
}

