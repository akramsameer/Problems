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
int main() {
	file();
	int n  ;
	string l , o ;
	cin>> n;
	cin >> l >> o;
	int ans = 0;
	for(int i = 0 ; i < n ; i++){
		int k = l [i] - '0' , c = o[i] - '0';
		ans += min(abs(k - c) ,  9 - abs(k - c )+1	);
	}
	cout<< ans<<endl;
	return 0;
}
