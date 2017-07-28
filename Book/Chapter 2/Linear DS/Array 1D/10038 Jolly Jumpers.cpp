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
	int n;
	while(cin >> n){
		bool vis[3000+9] = {0};
		int prev;
		cin >>  prev ;
		for(int i = 1 ; i < n ; i++	){
			int x ;
			cin >> x ;
			vis[abs(x-prev)] = 1;
			prev = x;
		}
		bool ans = 1;
		for(int i = 1 ; i < n ;i++)
			if(!vis[i])
				ans = 0;

		if(ans)
			printf("Jolly\n");
		else
			printf("Not jolly\n");
	}


	return 0;
}

