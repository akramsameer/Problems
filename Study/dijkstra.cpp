#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const int oo = 1e8;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

struct edge {
	int from , to , w;
	edge(int from , int to , int w): from(from) , to(to) , w(w){}

	bool operator < (const edge & e)const{
		return w > e.w;
	}
};

int dijkstra(vector< vector<edge> > adjList  , int src , int dest = -1) { //O(E logV)
	int n = adjList.size();
	vi dist (n , oo) , prev(n , oo);
	dist[src] = 0;

	priority_queue<edge> q;
	q.push(edge(-1 , src , 0));

	while(!q.empty()){
		edge e = q.top(); q.pop();

		if(e.w > dist[e.to])	continue;

		prev[e.to] = e.from;

		for (int i = 0; i < adjList[e.to].size(); ++i) {
			edge ne = adjList[e.to][i];
			if(dist[e.to] > dist[ne.from] + ne.w){
				ne.w = dist[ne.to] = dist[ne.from] + ne.w;
				q.push(ne);
			}
		}
	}

	return dest == -1?-1 : dist[dest];
}

int main() {

	return 0;
}
