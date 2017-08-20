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
int k  , arr[12] , ans = OOI;
int main() {
	file();
	cin>>k;

	for(int i = 0 ; i < 12 ; i++)
		cin >> arr[i];

	for(int i = 0 ; i < (1 << 12) ; i++){
		int count = 0 , g = 0 ;

		for(int j = 0 ; j < 12 ;j++)
			if(i &(1 << j)){
				count += 1;
				g += arr[j];
			}

		if(g >= k)
			ans = min(ans , count);
	}

	cout<<ans<<endl;
	return 0;
}
