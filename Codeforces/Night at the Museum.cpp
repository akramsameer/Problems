//============================================================================
// Name        : Night.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
string str;
int main() {
	cin>>str;
	int sum = 0;
	int cur = 0;
	for(int i = 0 ; i < str.length(); i++){
		int c = str[i] - 'a';

		int left =  cur - c ;
		if(left < 0)
			left += 26;

		int right = c - cur;
		if(right < 0)
			right +=26;

		sum += min(left , right);
		cur = c;
	}
	cout << sum <<endl;
	return 0;
}
