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
int t, n, len, arr[1000000 + 9];

int main() {
	file();
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &len, &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		int mi = 0, mx = 0;
		for (int i = 0; i < n; i++){
			mi = max(mi, min(len - arr[i], arr[i]));
			mx = max(mx , max(len - arr[i] , arr[i]));
		}
		cout << mi <<" "<< mx << endl;
	}
	return 0;
}
