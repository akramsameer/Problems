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

int d[] = {2 , 3 , 5};
ll num[2];
int x [2][3];
int main() {
	file();

	cin >> num[0] >> num[1] ;
	for(int i = 0 ; i < 2 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			while(num[i] % d[j] == 0){
				x[i][j]++;
				num[i] /= d[j];
			}
		}
	}

	if(num[0] != num[1]){
		cout<<"-1\n";
		return 0;
	}
	int ans = 0 ;
	for(int i = 0 ; i < 3 ; i++)
		ans += abs(x[0][i] -x[1][i]);

	cout<<ans<<"\n";
	return 0;
}

