//============================================================================
// Name        : Soft.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int n, k, l, c, d, p, nl, np;
int main() {
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int drink = (l * k )/nl;
	int slices = c*d;
	int salt = p / np;
	int ans = min(drink , min(slices, salt)) / n;
	cout<<ans<<endl;
	return 0;
}
