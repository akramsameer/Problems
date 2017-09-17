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
int xdir[] = { 1, -1, 0, 0 };
;
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
set<int> st;
int n, m, k;
ll arr[19];

int main() {
	file();
	while (cin >> n >> m) {
		if (n + m == 0)
			break;
		cin >> k;
		for (int i = 0; i < k + 1; i++)
			cin >> arr[i];
		for (int i = 0; i <= m; i++) {
			ll ans = arr[0];
			ll p = i;
			for (int j = 1; j < k + 1; j++) {
				ans = (ans + ((p * arr[j]) % (n + 1))) % (n + 1);
				p = (p * i) % (n + 1);
			}
			st.insert(ans);
		}
		printf("%d\n" , sz(st));
		st.clear();
	}

	return 0;
}

