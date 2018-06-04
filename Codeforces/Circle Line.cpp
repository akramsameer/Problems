//============================================================================
// Name        : Circle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int n, arr[101], s, e;
int main() {
	int i, sumr = 0, suml = 0;
	cin >> n;
	for (i = 1; i <= n; i++)
		cin >> arr[i];
	cin >> s >> e;
	i = s;
	while (i != e) {
		sumr += arr[i];
		i++;
		if(i >n)
			i%=n;
	}
	i = s;
	while (i != e) {
		i--;
		if (i < 0)
			i += n + 1;
		suml += arr[i];
	}
	cout << min(suml, sumr) << endl;
	return 0;
}
