//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

const int  MAX_N = 200000 ;
int corX[MAX_N] , corY[MAX_N] , n ;

int main() {
	while  (cin >> n && n ){
		for(int i = 0 ; i < n ; i++){
			cin >> corX[i]>>corY[i];
		}
		int midx = corX[n/2] , midy = corY[n/2];
		int st = 0 , ol = 0;
		for(int i = 0 ; i < n ;i++){
			if((corX[i] > midx && corY[i] > midy) || (corX[i] < midx && corY[i] < midy))
				st++;
			else if((corX[i] < midx && corY[i] > midy)||(corX[i] > midx && corY[i] < midy))
				ol++;
		}
		cout<< st << " "<<ol<<endl;
	}
	return 0;
}
