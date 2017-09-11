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
		if(rank[x] > rank[y]){
			par[y] = x;
			setSize[x] += setSize[y];
		}else{
			par[x] = y;
			setSize[y] += setSize[x];
			if(rank[x] == rank[y])
				rank[y]++;
		}
	}

	int numOfDisjointSets(){
		return numSets;
	}

	int sizeOfSet(int i){
		return setSize[findSet(i)];
	}

};

int n, m;
vector<pair<int, ii> > EdgeList;
int main() {
	file();
	while (cin >> n >> m) {
		if (!n && !m)
			break;
		int W = 0;
		EdgeList.clear();
		for (int i = 0; i < m; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			EdgeList.push_back(make_pair(z, ii(x, y)));
			W += z;
		}
		sort(EdgeList.begin(), EdgeList.end());
		int mst_cost = 0;
		UnionFind UF(n);
		for(int i = 0 ; i < m ; i++){
			pair<int , ii> front = EdgeList[i];
			if(!UF.isSameSet(front.second.first , front.second.second)){
				mst_cost += front.first;
				UF.unionSet(front.second.first , front.second.second);
			}
		}
		cout<< W - mst_cost<<endl;
	}
	return 0;
}

