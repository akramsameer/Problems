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
int n;
int main() {
	file();
	cin >> n;
	bool f = 1;
	for (int i = 0 , k = 0; i < n; i++) {
		if(i > n/ 2 && f){
			 k = n / 2 -1;
			 f = 0;
		}
		int d = 2 * k + 1;
		int rem = n - d ;
		for(int j = 0 ; j < rem / 2 ; j++)
			printf("*");
		for(int j = 0 ; j < d ; j++)
			printf("D");
		for(int j = 0 ; j < rem / 2 ; j++)
			printf("*");
		printf("\n");
		if(i > n / 2)
			k--;
		else
			k++;
	}
	return 0;
}
