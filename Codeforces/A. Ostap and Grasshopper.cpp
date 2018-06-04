//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;
int n ,  k , s , e ;
string str;
int main() {
	cin >> n >> k;
	cin.ignore();
	getline(cin , str);
	for (int i = 0; i < str.length(); ++i) {
		if(str[i] == 'G')
			s = i ;
		if(str[i] == 'T')
			e = i ;
	}
	int gap = abs(e - s)  ;

	if(gap % k != 0)
		cout<<"NO"<<endl;
	else
	{
		int ind = (s > e )? s : e;
		while(gap){
			gap = gap - k;
			ind = ind - k;

			if(str[ind] == '#'){
				cout <<"NO"<<endl;
				return 0;
			}
		}
		cout << "YES"<<endl;
	}
	return 0;
}
