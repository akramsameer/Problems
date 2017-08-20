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
int n , m , d[20000+9] , h[20000+9];
int main() {
	file();
	while(scanf("%d %d" , &n , &m)){
		if(!n && !m)
			break;
		for(int i = 0 ; i < n ; i++)
			scanf("%d" , &d[i]);

		for(int i = 0 ; i < m ;i++)
			scanf("%d" , &h[i]);
		sort(d , d+n);
		sort(h , h+m);
		int cnt , i , j ;
		i = j = cnt = 0;
		while(i < n && j < m){
			while(j < m && d[i] > h[j]) j++;
			if(j == m)break;
			cnt += h[j];
			i++ ; j++;
		}
		if(i==n) printf("%d\n" , cnt);
		else printf("Loowater is doomed!\n");
	}
	return 0;
}
