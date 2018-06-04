//============================================================================
// Name        : Uniform.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;
bool vis[100001];
int step, mod;
int gcd(int a , int b ){
	if(a % b == 0 )
		return b ;
	return gcd(b , a%b);
}
int main() {
	while (cin >> step >> mod) {
		bool norepeat = true;
		int ind = 0;
		vis[ind] = true;
		while (norepeat) {
			ind = (ind + step) % mod;
			if (!vis[ind])
				vis[ind] = true;
			else
				norepeat = false;
		}
		bool all = true;
		for (int i = 0; i < mod; i++) {
			if (!vis[i])
				all = false;
		}

		cout<<setw(10)<<step<<setw(10)<<mod<<"    ";
		if (all)
			cout << "Good Choice" << endl;
		else
			cout <<"Bad Choice" << endl;

		for(int i = 0 ; i < mod ; i++)
			vis[i]= false;
		cout<<endl;
	}
	return 0;
}
