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
class UnionFind {
private:
	vi par, rank, setSize;
	int numSets;
public:
	UnionFind(int N) {
		setSize.assign(N, 1);
		numSets = N;
		rank.assign(N, 0);
		par.assign(N, 0);
		for (int i = 0; i < N; i++)
			par[i] = i;
	}

	int findSet(int i) {
		return (par[i] == i) ? i : (par[i] = findSet(par[i]));
	}

	bool isSameSet(int i, int j) {
		return findSet(i) == findSet(j);
	}

	void unionSet(int i, int j) {
		int x = findSet(i), y = findSet(j);
		numSets--;
		if (rank[x] > rank[y]) {
			par[y] = x;
			setSize[x] += setSize[y];
		} else {
			par[x] = y;
			setSize[y] += setSize[x];
			if (rank[x] == rank[y])
				rank[y]++;
		}
	}

	int numOfDisjointSets() {
		return numSets;
	}

	int sizeOfSet(int i) {
		return setSize[findSet(i)];
	}

};

int n, m, cas = 1;
vector<pair<int, ii> > EdgeList;
vii adj[101];
vector<bool> vis;
int dfs(int ind, int en) {
	vis[ind] = 1;
	if (ind == en)
		return OOI;
	int ret = OOI;
	for (int i = 0; i < sz(adj[ind]); i++) {
		ii to = adj[ind][i];
		if (!vis[to.first])
			ret = min(ret, min(to.second, dfs(to.first, en)));

	}
	return ret;
}
int main() {
	file();
	while (cin >> n >> m) {
		if (n + m == 0)
			break;
		EdgeList.clear();
		for (int i = 0; i < 101; i++)
			adj[i].clear();

		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			EdgeList.push_back(make_pair(-c, ii(a, b)));
		}
		sort(EdgeList.begin(), EdgeList.end());
		UnionFind UF(n + 1);
		int st, en, t;
		cin >> st >> en >> t;
		for (int i = 0; i < m; i++) {
			pair<int, ii> front = EdgeList[i];
			if (UF.isSameSet(st, en))
				break;
			if (!UF.isSameSet(front.second.first, front.second.second)) {

				UF.unionSet(front.second.first, front.second.second);
				adj[front.second.first].push_back(
						make_pair(front.second.second, -front.first));
				adj[front.second.second].push_back(
						make_pair(front.second.first, -front.first));
			}
		}
		vis.assign(n + 1, 0);

		int cost = dfs(st, en);
		cost--;
		int ans = t / cost;
		if (t % cost > 0)
			ans++;
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", cas++, ans);
	}

	return 0;
}

