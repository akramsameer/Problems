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

int main() {
	file();
	int n , m ;
	cin >> n >> m;
	char c;
	bool color = 0;
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j< m ; j++){
			cin >> c;
			if(c =='C' || c == 'M' || c == 'Y')
				color = 1;
		}
	if(color)
		cout<<"#Color\n";
	else
		cout<<"#Black&White\n";

	return 0;
}
