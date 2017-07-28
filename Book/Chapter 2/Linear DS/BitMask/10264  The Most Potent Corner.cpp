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
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
int arr[40000], w[40000], n;
int main() {
	file();
	while (cin >> n) {
		clr(arr , 0);
		for (int i = 0; i < (1 << n); i++) {
			cin >> w[i];
		}
		for(int i = 0 ; i < (1 << n);i++){
			for(int j = 0 ; j < n ; j++){
				arr[i] += w[(i^(1 << j))];
			}
		}
		int res = 0;

		for (int i = 0; i < (1 << n); i++) {
			for (int j = 0; j <  n; j++) {

				res = max(res, (arr[i] + arr[(i ^ (1 << j))]));
			}
		}
		cout << res << endl;
	}
	return 0;
}
