//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;
int n = 0 , cnt = 1;
double xl[12], yh[12], xh[12], yl[12] , xp , yp;
char c;
int main() {
	while (cin >> c && c != '*') {
		cin >> xl[n] >> yh[n] >> xh[n] >> yl[n];
		n++;
	}

	while(cin >> xp >> yp && !(xp==9999.9 && yp==9999.9)){
		bool ntcont = true ;
		for(int  i = 0 ; i < n ; i++){
			if(xp  > xl[i] && xp < xh[i] && yp > yl[i] && yp < yh[i] ){
				cout<<"Point "<<cnt<<" is contained in figure "<<i+1<<"\n";
				ntcont = false;
			}
		}
		if(ntcont)
			 cout<<"Point "<<cnt<<" is not contained in any figure\n";
		cnt++;
	}
	return 0;
}
