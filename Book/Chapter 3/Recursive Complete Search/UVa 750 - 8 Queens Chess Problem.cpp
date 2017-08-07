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
#endif
}
int t , a , b , row[8]  , lineCounter ;

bool canPlace(int r , int c){
	for(int prev = 0 ; prev < c ; prev++)
		if(row[prev] == r || abs(row[prev] - r) == abs(prev - c))
			return false;
	return true;
}


void backtrack(int c){
	if(c == 8 && row[b] == a){
		printf("%2d      %d" , ++lineCounter , row[0] +1);
		for(int i = 1 ; i < 8 ; i++)
			printf(" %d" , row[i] +1);
		printf("\n");
	}
	for(int r = 0 ; r < 8 ; r++)
		if(canPlace(r , c)){
			row[c] = r;
			backtrack(c+1);
		}

}
int main() {
	file();
	scanf("%d" , &t);
	while(t--){
		scanf("%d %d" ,&a , &b);
		a-- , b--;
		clr(row , 0); lineCounter = 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		if(t)
			printf("\n");
	}
	return 0;
}
