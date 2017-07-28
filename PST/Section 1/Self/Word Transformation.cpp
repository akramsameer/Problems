//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
string words[201];
int cnt = 0;
struct node {
	string str;
	int lenght;
};
map<string, int> mp;
map<string, int>::iterator it;
int diff(string s1, string s2) {
	if (s1.size() != s2.size())
		return -1;
	int d = 0;
	for (int i = 0; i < s1.size(); ++i) {
		if (s1[i] != s2[i])
			d++;
	}
	return d;
}
int bfs(string s, string e) {
	if (s == e)
		return 0;
	int ans = 0;
	queue<node> Q;
	node no;
	no.str = s;
	no.lenght = ans;
	Q.push(no);

	while (Q.size()) {
		node nn = Q.front();
		Q.pop();

		if (nn.str == e)
			return nn.lenght;

		for (int var = 0; var < cnt; ++var)
			if (diff(nn.str, words[var]) == 1) {
				node temp;
				temp.str = words[var];
				temp.lenght = nn.lenght + 1;
				Q.push(temp);
			}
	}
	return -1;
}
void clearmap() {

}
int main() {
	int t;
	cin >> t;
	while (t--) {
		clearmap();
		getchar();
		string temp;
		cnt = 0;
		while (getline(cin, temp) && temp != "*")
			words[cnt++] = temp;
		string s, e;

		while (getline(cin, s) && s != "") {
			stringstream ss(s);
			ss >> s;
			ss >> e;
			int d = bfs(s, e);
			printf("%s %s %d\n", s.c_str(), e.c_str(), d);
		}

	}
	return 0;
}
