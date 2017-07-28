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
int pos[1000];
char arr[1000][1000];
int main() {
	file();
	int t;
	cin >> t;
	bool flag = 1 ;
	while (t--) {
		if(!flag)
			printf("\n");
		flag = 0 ;
		int ind = 0;
		while(true){
			int x;
			cin >> x ;
			pos[x -1] = ind++;
			if(getchar() == '\n')
				break;;
		}

		for(int i = 0 ; i < ind ; i++)
			scanf("%s" , arr[i]);

		for(int i = 0 ; i < ind ; i++)
			printf("%s\n" ,  arr[pos[i]]);
	}
	return 0;
}

