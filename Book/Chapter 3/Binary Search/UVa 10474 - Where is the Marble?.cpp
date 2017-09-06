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
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int n, q, arr[10000 + 9],l = 0;
int main() {
	file();
	while (cin >> n >> q) {
		if (!n && !q)
			break;

		for (int i = 0; i < n; i++)
			cin >> arr[i];

		sort(arr, arr + n);
		printf("CASE# %d:\n" , ++l);
		for (int i = 0; i < q; i++) {
			int x, ans;
			cin >> x;
			ans = lower_bound(arr, arr + n, x) - arr;
			if (arr[ans] == x)
				printf("%d found at %d\n", x, ans + 1);
			else
				printf("%d not found\n", x);
		}

	}
	return 0;
}
