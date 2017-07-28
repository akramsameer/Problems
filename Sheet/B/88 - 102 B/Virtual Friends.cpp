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
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
struct edge {
	int u, v, c;
	edge(int u, int v, int c) :
			u(u), v(v), c(c) {
	}
	bool operator <(const edge& e) const {
		return c > e.c;
	}
};

struct UnionFind {
	vi parent, rank , cap;
	UnionFind(int n) {
		parent = vi(n + 1);
		rank = vi(n + 1);
		cap = vi(n +1);
		for (int i = 0; i <= n; i++) {
			parent[i] = i;
			rank[i] = 1;
			cap[i] = 1;
		}
	}

	int find_set(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = find_set(parent[x]);
	}

	void link(int x, int y) {
		if (rank[x] > rank[y])
			swap(x, y);
		parent[x] = y;
		if (rank[x] == rank[y])
			rank[y]++;

		cap[y] += cap[x];
		cap[x] = cap[y];
	}

	pair<bool , int> union_set(int x, int y) {
		x = find_set(x);
		y = find_set(y);
		if (x != y)
			link(x, y);

		return make_pair(x != y , cap[x]);
	}
};

int main() {
	file();
	int t;
	const int MAXN = 100000;
	cin >> t;
	while (t--) {
		int f;
		cin >> f;
		UnionFind uf(MAXN);
		map<string, int> mp;
		int cnt = 1;
		while (f--) {
			string s1, s2;
			cin >> s1 >> s2;
			if (mp.find(s1) == mp.end())
				mp[s1] = cnt++;

			if (mp.find(s2) == mp.end())
				mp[s2] = cnt++;

			pair<bool, int> ans = uf.union_set(mp[s1], mp[s2]);
			cout << ans.second << endl;
		}
	}
	return 0;
}

