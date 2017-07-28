//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector <int> adjList[101];
int depth[101] , n;

void dfs(int cur , int d){
	depth[cur] = d ;
	for (int i = 0; i < adjList[cur].size(); ++i)
		dfs(adjList[cur][i] , d+1);
}
int length[101];
int dfs2(int cur , int d ){
	length[cur] = d ;
	for (int i = 0; i < adjList[cur].size(); ++i)
		length[cur] = max(length[cur] ,  dfs2(adjList[cur][i] , d+1));
	return length[cur];
}

int main() {
	cin >> n ;
	for (int i = 0; i < n-1; ++i) {
		int u , v ;
		cin >> u >> v ;
		adjList[u].push_back(v);
	}

	dfs(1 , 0);

	for (int i = 1; i <= n; ++i) {
		cout << i <<" --> " << depth[i] << endl;
	}
	dfs2(1 , 0);
	cout << "lenght"<<endl;
	cout << endl;
	for (int i = 1; i <= n; ++i) {
		cout << i << " --> "<< length[i] <<endl;
	}
	return 0;
}

// edge list ::
/*
 * 		vector< pair<int , int > > el
 * 		el.push_back(makepair(from , to))
 *
 * 		uses in --> minimum spanning tree
 *
 *  adjacency matrix ::
 *
 * 		int arr[100][100]
 * 		arr[2][5] =
 * 			==> cost edge from 2 to 5
 * 			==> if ( not exist ) cost  = 1e9
 *
 * 		uses in floyed warshal
 *
 * 	adjacency list ::
 *
 * 		vector <int> adjlist [100];
 * 		adjlist[5].push_back(2);
 *
 * 		if(hasCost)
 * 			vector < pair<int , int > > adjlist[100];
 *
 */

//	traverse Graph ::
/*	 	Tree ==> Directed Acyclic graph
 *
 * 		DFS:
 * 			start from the root
 *
 */

