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
	freopen("out.txt", "w", stdout);
#endif
}
int q , m ;
string movies[1000+9] , temp;
int sim(string mov , string cli){
	int ret = OOI;
	for(int i = 0 ; i + sz(cli)-1 < sz(mov) ; i++){
		int cnt = 0;
		for(int j = 0 ; j < sz(cli) ; j++){
			if(mov[i + j] !=cli[j])
				cnt++;
		}
		ret = min(ret , cnt);
	}

	return ret;
}
int main() {
	file();
	scanf("%d %d" , &m , &q);
	for(int i = 0 ; i< m ; i++)
		cin >> movies[i];

	while(q--){
		cin >> temp;
		int res = OOI , resId = -1;

		for(int i = 0 ; i < m ; i++){
			if(sz(movies[i]) >= sz(temp)){
				int x = sim(movies[i] , temp);
				if(x < res){
					res = x;
					resId = i+1;
				}
			}
		}

		printf("%d\n" , resId);
	}

	return 0;
}
