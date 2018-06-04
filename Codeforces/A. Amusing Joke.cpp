//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int letters[26];
string str1, str2, arr;
int main() {
	int i;
	cin >> str1;
	cin >> str2;
	cin >> arr;

	for (i = 0; i < str1.size(); ++i)
		letters[(str1[i] - 'A')]--;
	for (i = 0; i < str2.size(); ++i)
		letters[(str2[i] - 'A')]--;

	for (i = 0; i < arr.size(); ++i) {
		letters[(arr[i] - 'A')]++;
	}
	bool ans = true;
	for (i = 0; i < 26; ++i)
		if(letters[i] != 0){
			ans =  false;
			break;
		}

	if(ans )
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
