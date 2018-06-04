//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int n, m, arrN[10001], arrM[10001], count = 0, maxC = 0;
int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arrN[i];
	cin >> m;
	for (int i = 0; i < m; ++i)
		cin >> arrM[i];

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (arrM[i] % arrN[j] == 0 && (arrM[i] / arrN[j]) > maxC) {
				maxC = arrM[i] / arrN[j];
				count = 1;
			} else if (arrM[i] % arrN[j] == 0 && arrM[i] / arrN[j] == maxC)
				count++;
	cout <<  count<<endl ;
	return 0;
}
