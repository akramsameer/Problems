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
int t , n , m  , arr[8 +9] [39];
int main() {
	file();
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0 ; i < n ;i++)
			for(int j = 0 ; j < m ; j++)
				cin >> arr[i][j];
		bool ans = 1;
		for(int i = 0 ; i < m ; i++){
			int sum = 0 ;
			for(int j = 0 ; j < n ; j++){
				sum += arr[j][i];
			}
			if(sum != 2)
				ans = 0;
		}
		if(ans){
			bool vis[8 +3][8+3];
			clr(vis , 0);

			for(int i = 0 ; i < m ; i++){
				int first , second , j = 0 ;
				while(arr[j++][i] != 1);
				first = j -1;
				while(arr[j++][i] != 1);
				second = j -1;

				if(!vis[first][second])
					vis[first][second] = vis[second][first] = 1;
				else
					ans = false;
			}
		}
		if(ans)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
