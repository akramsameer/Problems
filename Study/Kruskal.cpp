#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };

struct UnionFind{
	vi rank , parent;
	int forests;

	UnionFind(int n){
		rank = vi(n) , parent= vi(n);
		forests = n ;

		for (int i = 0; i < n; ++i)
			parent[i] = i , rank[i] = 1 ;
	}

	int find_set(int x){
		if(x == parent[x])return x;
		return parent[x] = find_set( parent[x] );
	}

	void link(int x , int y){
		if(rank[x] > rank[y])
			swap(x , y);
		parent[x] = y ;
		if(rank[x] == rank[y])
			rank[y]++;
	}

	bool union_sets(int x , int y){
		x = find_set(x) , y = find_set(y);
		if( x != y ){
			link(x , y);
			forests--;
		}
		return x!=y;
	}


	vector <vi> connected_components(){
		vector<vi> list (parent.size());
		for (int i = 0; i < parent.size(); ++i)
			list[find_set(i)].push_back(i);
		return list;
	}
};

struct edge {
	int from , to , w ;

	edge(int from , int to , int w ):from (from) , to (to) , w(w){}

	bool operator < (const edge & e)const {
		return w > e.w;
	}
};


pair<int , vector<edge> > MST_Kruskal (vector<edge> edgeList , int n){ // O(E logV)
	UnionFind uf(n);
	vector<edge> edges ; // save MST edges
	int mstCost = 0 ;
	priority_queue<edge> q ;
	for (int i = 0; i < edgeList.size(); ++i)
		q.push(edgeList[i]);

	while( !q.empty() ){
		edge e = q.top();	 q.pop();

		if(	uf.union_sets(e.from , e.to) ){
			mstCost += e.w;
			edges.push_back(e);
		}
	}

	if(edges.size() != n-1)		return make_pair(-OO , vector<edge>() );
	return make_pair(mstCost , edges);

}
