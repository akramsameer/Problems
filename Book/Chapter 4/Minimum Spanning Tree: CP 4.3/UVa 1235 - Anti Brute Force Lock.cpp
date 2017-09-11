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
int t, n;
char arr[501][5];
vector<pair<int, ii> > EdgeList;
int dist(int a, int b) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		int x = arr[a][i] - '0';
		int y = arr[b][i] - '0';
		ret += min(abs(x - y), 10 - abs(x - y));
	}
	return ret;
}

int main() {
	file();
	cin >> t;
	while (t--) {
		cin >> n;
		arr[0][0] = arr[0][1] = arr[0][2] = arr[0][3] = '0';
		EdgeList.clear();
		for (int i = 1; i <= n; i++)
			scanf("%s", arr[i]);

		UnionFind UF(n + 1);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				int d = dist(i, j);
				EdgeList.push_back(make_pair(d, ii(i, j)));
			}
		}
		int mst_cost = 0;
		bool flag = 0;
		sort(EdgeList.begin(), EdgeList.end());
		for (int i = 0; i < sz(EdgeList); i++) {
			pair<int, ii> front = EdgeList[i];
			if (!UF.isSameSet(front.second.first, front.second.second)) {
				if (front.second.first == 0 || front.second.second == 0) {
					if (flag)
						continue;
					else
						flag = true;
				}
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}
		cout << mst_cost << endl;

	}
	return 0;
}

