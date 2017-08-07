#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
#define isPowerOfTwo(S) (!(S & (S - 1)))
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
//	freopen("out.txt", "w", stdout);
#endif
}
int t, d, n, board[1024 + 9][1024 + 9];

int main() {
	file();
	scanf("%d" , &t);
	while(t--){
		clr(board , 0);
		scanf("%d" , &d);
		scanf("%d" , &n);
		int x , y , cost;
		for(int i = 0 ; i < n ; i++){
			scanf("%d %d %d" , &x , &y , &cost);
			for(int j = max((x-d) , 0) ; j <= min(1024 , x+d) ; j++)
				for(int k = max(0 , y-d) ; k <= min(1024 , y+d) ; k++)
					board[j][k] += cost;
		}
		int resx , resy  , mx = 0;
		for(int i = 0 ; i <= 1024 ; i++)
			for(int j = 0 ; j <= 1024 ; j++)
				if(mx < board[i][j]){
					resx = i ;
					resy = j ;
					mx = board[i][j];
				}

		printf("%d %d %d\n" , resx , resy , mx);
	}
	return 0;
}
