//============================================================================
// Name        : Street.cpp
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
struct spot {
	double h, w, d, cost;
	int ind;
	bool dir;
};

bool operator <(spot a, spot b) {
	if (a.cost != b.cost)
		return a.cost < b.cost;
	return a.ind < b.ind;
}

int t, n, l, u;
spot arr[10003];
double dis[103];
vector<double> c[103];
vector<int> grph[103];
set<spot> S;
int dijkestra() {
	spot cur;
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

		if (cur.ind == n+1)
			return cur.cost;

		for (int i = 0; i < grph[cur.ind].size(); i++) {
			spot temp;
			temp.ind = grph[cur.ind][i];
			temp.cost = cur.cost + c[cur.ind][i];
			if (dis[temp.ind] == -1)
				S.insert(temp);
		}

	}
	return -1;
}
int main() {
	int i;
	cin >> t;
	cin >> n >> l >> u;

	for (i = 1; i <= n; i++) {
		cin >> arr[i].h >> arr[i].w >> arr[i].d >> arr[i].dir;
		arr[i].ind = i;
	}
	arr[102].d = 200;
	arr[102].h = 0;
	arr[102].w = 0;

	for (i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == j)
				continue;

			grph[i].push_back(j);
			grph[j].push_back(i);

			if (arr[i].dir == arr[j].dir) {
				double temp;
				if (arr[i].d < arr[j].d) {
					temp = arr[j].d - (arr[i].d + arr[i].h);
				} else
					temp = arr[i].d - (arr[j].d + arr[j].h);
				c[i].push_back(temp);
				c[j].push_back(temp);

			} else {
				if (arr[i].d + arr[i].h > arr[j].d
						&& arr[i].d + arr[i].h < arr[j].d + arr[j].h) {
					c[i].push_back(100 - (arr[i].w + arr[j].w));
					c[j].push_back(100 - (arr[i].w + arr[j].w));
				} else if (arr[j].d + arr[j].h > arr[i].d
						&& arr[j].d + arr[j].h < arr[i].d + arr[i].h) {
					c[i].push_back((100 - (arr[i].w + arr[j].w)));
					c[j].push_back((100 - (arr[i].w + arr[j].w)));
				} else if (arr[i].d + arr[i].h < arr[i].d
						|| arr[j].d + arr[j].h < arr[i].d) {
					double totalw = 100 - (arr[i].w + arr[j].w);
					double totalh = max(arr[i].d, arr[j].d)
							- min(arr[i].d, arr[j].d);
					c[i].push_back(sqrt(totalw * totalw + totalh * totalh));
					c[j].push_back(sqrt(totalw * totalw + totalh * totalh));
				}
			}
		}
	}

	cout << dijkestra() << endl;

	return 0;
}
