#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };


int pionter() {
	int arr[5] = {8,6,2,4,3};

	//compiler creates an internal POINTER for and store the arrary's starting address
	cout<<arr<<endl;
	cout<<&arr[0]<<endl;

	// int *ptr = arr[0] // WRONG arr[0] is not address
	int *pre = &arr[0];  //equivalent to int *ptr = arr ;

	//const and pointer

	int val1 = 	20;

	int *ptr = new int ;
	*ptr = 10;			// can change data , it's not a constant
	ptr = &val1;		// can change pointer , it's not a constant

	const int* ptr2 = new int ;
	// ptr2  = 20 			// can't do this , constant data

	const int* ptr3 = &val1;
	//ptr3 = 20   			// can't do this , constant data;
	ptr3 = ptr;				// Can change pointer , it is not constant


	int* const ptr4 = new int;
	*ptr4 = 20;				// Can change data , it's not a constant
	//ptr4 = ptr			//can't do this

	const int* const ptr5 = &val1;
	//*ptr5 = 20			// Can't do this , constant data
	// ptr5 = ptr			// Can't do this , constant pointer


	return 0;
}
