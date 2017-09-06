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
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
const int N = 100000 + 5;
ll arr[N];
ll tree[4 * N];

ll merge(ll x, ll y, bool f) {
	if (f) {
		int res = x | y;
		return res;
	}
	else {
		int res = x ^ y;
		return res;
	}
}

bool build(int ind, int st, int en) {

	if (st == en) {
		tree[ind] = arr[st];
		return 1;
	}

	int mid = (st + en) / 2;
	int right = 2 * ind + 1;
	int left = 2 * ind;

	bool q1 = build(left, st, mid);
	bool q2 = build(right, mid + 1, en);

	if (q1)
		tree[ind] = merge(tree[right], tree[left], true);
	else
		tree[ind] = merge(tree[right], tree[left], false);

	return !q1;
}

//ll query(int ind, int st, int en, int i, int j) {
//	if (j < st || en < i)			// no intersect
//		return 1;
//
//	if (i <= st && en <= j)  		// begin & end in [i ... j]
//		return tree[ind];
//
//	int mid = (st + en) / 2;
//	int left = 2 * ind;
//	int right = 2 * ind + 1;
//
//	ll q1 = query(left, st, mid, i, j);
//	ll q2 = query(right, mid + 1, en, i, j);
//
//	return merge(q1, q2);
//}
//int update(int pos, int st, int en, int idx, int val) {
//	if (idx < st || idx > en)
//		return -1;
//
//	if (st == en && idx == en) {
//		tree[pos] = val;
//		arr[idx] = val;
//
//		return 1;
//	}
//	int mid = (st + en) / 2;
//	int left = 2 * pos;
//	int right = 2 * pos + 1;
//
//	int q1 = update(left, st, mid, idx, val);
//	int q2 = update(right, mid + 1, en, idx, val);
//	if (q1 == 0 || q2 == 1 || q1)
//		tree[pos] = merge(tree[right], tree[left]);
//}
int main() {
	file();
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= 1<< n; i++)
		cin >> arr[i];
	build(1, 1, pow(2 , n));
	cout << tree[1] << endl;
	for (int i = 0; i < m; i++) {
		int idx, val;
		cin >> idx >> val;

	}
	return 0;
}
