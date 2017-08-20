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
struct packet {
	int msg_id;ll start, end;

} arr[1000 + 9];
int n, m, lineCounter = 1, idx[10];
ll si[10];
vector<bool> vis[6];
ll solve() {
	for (int i = 0; i < n; i++)
		vis[i] = vector<bool>(si[i] + 1, 0);

	int ind = 0;

	int nxt = idx[ind++];
	ll ret = 0;
	for (int i = 0; i < m; i++) {
		int pac = (arr[i].end - arr[i].start) + 1;

		for (int j = arr[i].start; j <= arr[i].end; j++)
			vis[arr[i].msg_id - 1][j] = 1;

		bool stay = 0;
		for (int j = arr[i].start; j >= 1; j--)
			if (!vis[arr[i].msg_id - 1][j]) {
				stay = 1;
				break;
			}

		if (nxt == arr[i].msg_id - 1 && !stay) {
			bool go_nex = 1;
			for (int j = 1; j <= si[nxt]; j++)
				if (!vis[nxt][j])
					go_nex = 0;
			if (go_nex)
				nxt = idx[ind++];
		} else
			ret += pac;

	}
	return ret;
}
int main() {
	file();
	bool fi = 1;
	while (scanf("%d %d", &n, &m)) {
		if (!n && !m)
			break;
		if (!fi)
			printf("\n");
		fi = 0;
		for (int i = 0; i < n; i++)
			cin >> si[i], idx[i] = i;

		for (int i = 0; i < m; i++)
			cin >> arr[i].msg_id >> arr[i].start >> arr[i].end;
		ll res = OO;

		do {
			res = min(res, solve());
		} while (next_permutation(idx, idx + n));

		printf("Case %d: %lld\n", lineCounter++, res);
	}

	return 0;
}
