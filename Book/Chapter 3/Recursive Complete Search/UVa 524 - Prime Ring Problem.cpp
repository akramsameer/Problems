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
int n, lineCounter = 1, ans[30];
bool prime[50], vis[30];
void theive() {
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= 49; i++)
		for (int j = i * i; j <= 49; j += i)
			prime[j] = 0;
}

void backtrack(int ind) {
	if (ind == n) {
		cout << ans[0];
		for (int i = 1; i < n; i++)
			printf(" %d", ans[i]);
		printf("\n");
		return;
	}
	for (int i = 2; i <= n; i++) {
		if (prime[i + ans[ind - 1]] && !vis[i]) {
			if(ind == n-1 && !prime[i +1])
				continue;

			vis[i] = 1;
			ans[ind] = i;
			backtrack(ind + 1);
			vis[i] = 0;
		}

	}

}
int main() {
	file();
	clr(prime, 1);
	theive();
	bool  fi = 1;
	while (scanf("%d" , &n) != EOF) {
		if(!fi)
			printf("\n");
		fi = 0;
		printf("Case %d:\n", lineCounter++);
		clr(vis, 0);
		ans[0] = 1;
		vis[1] = 1;
		backtrack(1);
	}
	return 0;
}
