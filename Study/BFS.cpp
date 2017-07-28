#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;

vector<int> BFS(int s, vector<vector<int> > & adjList) {
	vector<int> len(adjList.size(), 1e9);
	queue<pair<int, int> > q;
	q.push(make_pair(s, 0)), len[s] = 0;

	int cur, dep;
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		cur = p.first;
		dep = p.second;
		for (int i = 0; i < adjList[cur].size(); ++i)
			if (len[adjList[cur][i]] == 1e9)
				q.push(make_pair(adjList[cur][i], dep + 1)), len[adjList[cur][i]] =
						dep + 1;
	}
	return len;
	// cur now is the furthest node from s with depth dep
}

// BFS without pair
vector<int> BFS2(int s, vector<vector<int> > & adjList) {
	vector<int> len(adjList.size(), 1e9);
	queue<int> q;
	int dep = 0, cur = s, sz = 1;
	for (; !q.empty(); ++dep, sz = q.size()) {
		while (sz--) {
			cur = q.front(), q.pop();
			for (int i = 0; i < adjList[cur].size(); ++i)
				if(len[adjList[cur][i]] == 1e9)
					q.push(adjList[cur][i]) , len[adjList[cur][i]] = dep;
		}
	}
	return len;
}


// path in BFS
vector <int> BFSPath(int s , int d , vector< vector<int> > & adjList){
	vector<int> len(adjList.size() , 1e9);
	vector<int> par(adjList.size() , -1);
	queue<int> q;
	q.push(s) , len[s] = 0;

	int dep = 0 , cur= s , sz = 1;
	bool ok = true;

	for(; ok && !q.empty() ; ++dep , sz = q.size()){
		while(ok && sz--){
			cur = q.front() , q.pop();
			for (int i = 0; i < adjList[cur].size() ; ++i)
				if(len[adjList[cur][i]] == 1e9){
					q.push(adjList[cur][i]);
					len[adjList[cur][i]] = dep +1;
					par[adjList[cur][i]] = cur;
					if(adjList[cur][i] == d){
						ok =false;
						break;
					}
				}

		}
	}

	vector<int> path;
	while(d != -1){
		path.push_back(d);
		d = par[d];
	}

	reverse( path.begin() , path.end());

	return path;
}



