//  Created by wander on 16/5/14.
//  Copyright © 2016年 W4anD0eR96. All rights reserved.

#include "bits/stdc++.h"
using namespace std;

void MergeWithCountInversions(vector<int>& v, int p, int q, int r, int& cnt) {
	int n1 = q - p, n2 = r - q;
	vector<int> L, R;
	for (int i = 0; i < n1; ++i)
		L.push_back(v[p + i]);
	for (int i = 0; i < n2; ++i)
		R.push_back(v[q + i]);
	L.push_back(INT_MAX);
	R.push_back(INT_MAX);

	int i = 0, j = 0;
	for (int k = p; k < r; ++k) {
		if (L[i] <= R[j]) {
			v[k] = L[i];
			i += 1;
		} else {
			v[k] = R[j];
			j += 1;
			cnt += n1 - i;

		}
	}
}

void MergeSort(vector<int>& v, int p, int r, int& cnt) {
	if (p >= r - 1)
		return;
	int q = (p + r) >> 1;
	MergeSort(v, p, q, cnt);
	MergeSort(v, q, r, cnt);
	MergeWithCountInversions(v, p, q, r, cnt);
}

int main(int argc, const char * argv[]) {
	int t ;
	cin >> t ;
	while(t--){
		int n , x;
		cin >> n;
		vector<int> v ;
		for(int i= 0 ; i < n ;i++){
			cin >> x;
			v.push_back(x);
		}

		int cnt = 0 ;
		MergeSort(v , 0 , n , cnt);
		printf("Optimal train swapping takes %d swaps.\n" , cnt);
	}
	return 0;
}
