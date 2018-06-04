//============================================================================
// Name        : Is.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
long arr[4];
set<int> S;
int main() {
	cin >> arr[0]>>arr[1]>>arr[2]>>arr[3];
	int i = 0;
//	while(i < 4){
//		S.
//	}

	int sum = 0;
	for(int i = 0 ; i < 4 ; i++){
		int k = 0;
		for(int j = i+1 ; j < 4 ; j++){
			if(i == j)
				continue;
			if(arr[i] == arr[j])
				k++;
		}
		i +=k;
		sum +=k;
	}
	cout << sum <<endl;
	return 0;
}
