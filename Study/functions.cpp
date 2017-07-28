//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#define ll long long
using namespace std;



ll GCD(ll a, ll b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}



//	lower_bound (start , end , item ) - arr ==> to get the first index of the item
//	lower_bound (start , end , item ) - arr ==> to get the last index of the item
	int indh = lower_bound(arr.begin() , arr.end() , arr[n-1]) - arr.begin();
	int indl = upper_bound(arr.begin() , arr.end() , arr[0]) - arr.begin();


