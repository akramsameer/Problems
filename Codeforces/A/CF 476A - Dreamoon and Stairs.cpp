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

int main() {
	file();
	int n , m;
	cin >> n >> m;
	if(m > n )
		cout<<"-1"<<endl;
	else{
		int twos= 0 , ones = 0;
		twos = n  / 2;
		if(n % 2)
			ones ++;
		for(int i = 1 ; m * i <= n;i++){
			int req =( m * i)  - (twos + ones);
			if(m * i < twos + ones)
				continue;
			ones += req * 2;
			twos = twos - req;
			for(int i = 0 ;i < twos ; i++)
				cout<<"2 ";
			for(int i = 0 ; i< ones ; i++)
				cout<<"1 ";
			return 0;
		}
	}
	return 0;
}
