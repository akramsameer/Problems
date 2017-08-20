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
int t, n, lineC = 1;
char arr[100 + 9], vis[100 + 9];

int main() {
	file();
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		clr(vis, 0);
		int cnt = 0;
		for (int i = 1; i < n; i++) {
			if (vis[i])
				continue;
			if (arr[i - 1] == '.' && !vis[i - 1]) {
				cnt++;
				vis[i] = vis[i - 1] = vis[i + 1] = 1;
			} else if (arr[i] == '.' && !vis[i]) {
				if (i == n - 1)
					cnt++;
				else
					continue;
			}
		}
		printf("Case %d: %d\n", lineC++, cnt);

	}
	return 0;
}
