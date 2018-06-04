//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
string str , word = "HQ9";

int main() {
	getline(cin  , str);
	bool ans = false;
	for (int i = 0; i < str.size(); ++i) {
		for (int j = 0; j < 3; ++j) {
			if(str[i] == word[j]){
				ans = true;
				break;
			}
		}
	}
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
