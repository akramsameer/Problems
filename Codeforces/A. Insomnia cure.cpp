//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int k, l, m, n, d, arr[4];
int inc_exe(int ind = 0, int k = 1, int sign = -1) {
	if (ind == 4) {
		if (k == 1)
			return 0;
		return sign * d / k;
	}
	return inc_exe(ind + 1, k, sign) + inc_exe(ind + 1, k * arr[ind], sign * -1);
}

int main() {
	for(int i = 0 ; i < 4 ; i++)
		cin >>arr[i];
	cin >>d;
	int ans = inc_exe();
	for (int i = 0; i < 4; ++i) {
		if(arr[i] == 1){
			ans = d;
			break ;
		}
		for(int j = 0 ;j<4 ; j++){
			if(i ==  j)
				continue;
			if(arr[j] % arr[i] == 0)
				ans--;
		}
	}

	cout<<ans<<endl;
	return 0;
}
