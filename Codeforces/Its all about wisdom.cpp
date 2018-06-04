//============================================================================
// Name        : Its.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <set>
#include <math.h>
#include <string.h>
using namespace std;
struct node {
	int ind;
	long cost;
};

bool operator <(node a, node b) {
	if (a.cost != b.cost)
		return a.cost < b.cost;
	return a.ind < b.ind;
}

int n, m, t, f, s, cost;
long long int dis[100001], k, w;
vector<int> arr[100001];
vector<int> c[100001];
vector<long> wis[100001];
set<node> S;

bool dijkstra(long long int o) {
	node cur;
	memset(dis, -1, sizeof dis);

	cur.ind = 0;
	cur.cost = 0;
	S.insert(cur);

	while (S.size()) {
		cur = *S.begin();
		S.erase(S.begin());
		if (dis[cur.ind] != -1)
			continue;

		dis[cur.ind] = cur.cost;
		if (cur.ind == n){
			cout << cur.cost<<endl;
			return cur.cost < k;
		}
		for (int i = 0; i < arr[cur.ind].size(); i++) {
			node temp;
			temp.ind = arr[cur.ind][i];
			temp.cost = cur.cost + c[cur.ind][i];
			if (dis[temp.ind] == -1 && wis[cur.ind][i] <= o)
				S.insert(temp);
		}
	}
	return 0;
}
int main() {
	cin >> t;
	while (--t) {
		cin >> n >> m >> k;
		for (int i = 0; i < m; i++) {
			cin >> f >> s >> cost >> w;
			arr[f].push_back(s);
			c[f].push_back(cost);

			arr[s].push_back(f);
			c[s].push_back(cost);

			wis[f].push_back(w);
			wis[s].push_back(w);
		}
		long long int s = 0, e = 1e10;
		long long int res = -1;
		while (s <= e) {
			long long int mid = (s + e) / 2;
			if (dijkstra(mid)) {
				e = mid - 1;
				res = mid;
				cout << "here" << endl;
			} else {
				s = mid + 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}
