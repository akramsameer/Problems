//============================================================================
// Name        : InsertionSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
using namespace std;
int arr[1000], t ;
int main() {
	scanf("%d" , &t);
	for (int i = 0; i < t; ++i) {
		scanf("%d" , &arr[i]);
	}

	//begin of Insertion Sort

	for (int i = 1; i < t; ++i) {
		int key = arr[i];
		int j = i -1 ;
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key ;
	}

	//display the array

	for (int i = 0; i < t; ++i) {
		printf("%d ",arr[i]);
	}
	return 0;
}
