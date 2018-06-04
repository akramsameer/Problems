//============================================================================
// Name        : Trees.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;
vector<int> adj(256);
string str;
int maxPos = 0;
void make_adj(int val, string s) {
	int pos = 1;
	// to get the right position
	for (int i = 0; i < s.size(); ++i) {
		pos *= 2;
		if (s[i] == 'R')
			pos++;
	}

	adj[pos] = val;
	if(maxPos < pos)
		maxPos = pos;
	return ;
}

int main() {

	while (true) {
		cin >> str;
		if (str.size() <= 2)
			break;
		bool isdigit = true;
		int n = 0;
		string s = "";
		for (int i = 1; i < str.size() - 1; ++i) {
			if (str[i] == ',') {
				isdigit = false;
				continue;
			}
			if (isdigit) {
				int d = str[i] - '0';
				n = (n* 10) + d;
			} else {
				s += str[i];
			}
		}

		make_adj(n, s);
	}

	//to check if its complete or not
	bool complete = true;

	for (int i = 2; i <= maxPos; ++i) {
		if(adj[i] == 0 )continue;

		int parent = i / 2;

		if (adj[parent] == 0)
			complete = false;
	}

	if(complete)
		for (int i = 1; i <= maxPos; ++i) {
			if(adj[i]==0)continue;
			if(i == maxPos){
				cout<<adj[i];
				continue;
			}
			cout<<adj[i]<<" ";
		}
	else
		cout<<"not complete";
	cout<<endl;
	return 0;
}
