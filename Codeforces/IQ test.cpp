//============================================================================
// Name        : Working.cpp
// Author      : Akram
// Version     :
// Copyright   : Your copyright notice
// Description : Code c++
//============================================================================

#include <iostream>

using namespace std;

int n , arr[101];
int main() {
	cin >> n ;
	for (int i = 0; i < n; ++i) {
		cin>> arr[i];
	}
	int lstodd = 0 , lsteven = 0 , cntodd = 0, cnteven = 0;
	for (int k = 0; k < n; ++k) {
		if((arr[k] & 1) == 0){
			cnteven++;
			lsteven = k;
		}
		else{
			cntodd++;
			lstodd = k;
		}
	}
	if(cntodd > cnteven){
		cout<<lsteven +1 <<endl;
	}else{
		cout << lstodd +1 <<endl;
	}
	return 0;
}
