//============================================================================
// Name        : Team.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int arrp[5000], arrm[5000], arrs[5000];
int n, p = 0, m = 0, s = 0;
char arr[5001];
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> arr[i];
		if (arr[i] == '1') {
			arrp[p] = i+1;
			p++;
		} else if (arr[i] == '2') {
			arrm[m] = i+1;
			m++;
		} else if (arr[i] == '3') {
			arrs[s] = i+1;
			s++;
		}
	}
	int ans = min(p , min(m , s));
	cout<<ans <<endl;
	for(int i = 0 ; i < ans ; i++){
		cout<< arrp[i]<<" "<<arrm[i]<<" "<<arrs[i]<<endl;
	}
	return 0;
}
