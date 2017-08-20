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
	//freopen("out.txt", "w", stdout);
#endif
}
int n  , cas ,  p , q , x , t , arr[35];
int main() {
	file();
	scanf("%d" , &t);
	while(t--){
		scanf("%d %d %d" , &n , &p , &q);
		int w , cnt ;
		w = cnt = 0;
		for(int i =0 ; i < n ; i++)
			scanf("%d",&arr[i]);

		int i = 0;
		while(i < n && cnt < p && w+arr[i] <= q){
				cnt++;
				w += arr[i];
				i++;
		}

		printf("Case %d: %d\n" , ++cas ,cnt);
	}
	return 0;
}
