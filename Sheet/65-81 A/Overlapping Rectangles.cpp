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

int t, x, y, xx, yy, xl, yl, xxl, yyl;
int main() {
	bool line = true;
	cin >> t;
	while (t--) {
		cin >> x >> y >> xx >> yy;
		cin >> xl >> yl >> xxl >> yyl;
		int X = max(x, xl);
		int Y = max(y, yl);
		int XX = min(xx, xxl);
		int YY = min(yy, yyl);

		if (line)
			cout << endl;
		line = true;

		if (X < XX && Y < YY)
			cout << X<<" " << Y<<" " << XX<<" " <<  ""<<YY << endl;
		else
			cout << "No Overlap" << endl;
	}
	return 0;
}
