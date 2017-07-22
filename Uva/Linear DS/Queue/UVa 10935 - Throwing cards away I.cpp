//============================================================================
// Name        : Working.cpp
// Author      : Akram
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <bits/stdc++.h>
using namespace std;
int n;
queue<int> q;
int main() {
	//freopen("in.txt", "r", stdin);
	int n;
	while (cin >> n, n) {
		while (q.size())
			q.pop();
		vector<int> ans;
		for (int i = 1; i <= n; i++)
			q.push(i);
		while (q.size() > 1) {
			ans.push_back(q.front());
			q.pop();
			int temp = q.front();
			q.pop();
			q.push(temp);
		}
		int sz = ans.size();
		if(sz != 0)
		printf("Discarded cards: ");
		else
			printf("Discarded cards:\n");
		for (int i = 0; i < sz; i++) {
			if (i != sz - 1)
				printf("%d, ", ans[i]);
			else
				printf("%d\n", ans[ans.size() - 1]);
		}

		printf("Remaining card: %d\n", q.front());
	}
	return 0;
}

