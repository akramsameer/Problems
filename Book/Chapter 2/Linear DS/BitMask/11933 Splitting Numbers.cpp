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



int main() {
	file();
	int n  ;
	while(cin >> n , n){
		int a = 0 , b = 0 , i = 0 , j = 0 ;
		while(n > 0){
			if(n & 1){
				if(j&1)
					a |=  (1 << i);
				else
					b |= (1 << i);
				j++;
			}
			i++;
			n =  n >> 1;
		}
		printf("%d %d\n" , b , a);
	}


	return 0;
}
