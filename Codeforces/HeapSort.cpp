//============================================================================
// Name        : HeapSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int array[1000] , n;
int heapsize = 0;
void maxHeapify(int i) {
	int left = i * 2;
	int right = i * 2 + 1;
	int largest;

	if(left <= heapsize && array[i] < array[left])
		largest = left;
	else
		largest = i;

	if(right <= heapsize && array[right] > array[largest])
		largest = right;

	if(largest != i)
	{
		int temp= array[largest];
		array[largest] = array[i];
		array[i] = temp;

		maxHeapify(largest);
	}
}

void BuildMaxHeap(){
	heapsize = n ;
	for (int i = n/2 ; i >= 1; i--) {
		maxHeapify(i);
	}
}

void sortHeap(){
	BuildMaxHeap();
	for (int i = 1; i <= n; i++) {
			cout<< array[i] << " ";
		}
	for (int i = n; i > 1  ; i--) {
		int temp= array[1];
		array[1] = array[i];
		array[i] = temp;

		heapsize--;
		maxHeapify(1);
	}
}

int main() {
	cin >> n ;
	for (int i = 1; i <= n; i++) {
		cin >> array[i];
	}
	sortHeap();
	cout << endl;
	for (int i = 1; i <= n; i++) {
		cout<< array[i] << " ";
	}
	return 0;
}
