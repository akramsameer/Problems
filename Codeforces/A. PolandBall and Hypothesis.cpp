//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	string arr;
	cin >> n >> m;
	cin>>arr;
	for (int i = 0; i < n; i += m) {
		if (arr[i] == '.') {
			continue;
		} else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
}
