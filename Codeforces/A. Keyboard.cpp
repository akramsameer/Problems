//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int ind[257];
char  k;
string str;
char keyboard[] = "qwertyuiopasdfghjkl;zxcvbnm,./";
int main() {
	cin >> k;
	int l = (k == 'R') ? -1 : 1;
	cin>>str;

	for(int i = 0 ; i < 30 ; i++){
		ind[keyboard[i]] = i ;
	}
	for(int i =0 ; i < str.size() ; i++){
		int idx = ind[str[i]];
		idx += l;
		cout<<keyboard[idx];
	}
	cout<<endl;
	return 0;
}
