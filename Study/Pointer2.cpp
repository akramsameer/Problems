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

ll n, k, arr[101];
bool vis[101];
int leader = 1;

int** create(){
	int **ptr = new int*[3];

	for (int i = 0; i < 3; ++i)
		ptr[i] = new int [2];

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			ptr[i][j] = (i+1) * (j+1);

	return ptr;
}

void free(int** ptr){
	for (int i = 0; i < 3; ++i)
		delete[] ptr[i];
	delete ptr;
}

int main() {
	//freopen("in.txt", "r", stdin);

	//Dynamic Array Allocation
	// New / Delete operators

	int num_employee;
	cin >> num_employee;

	int* employee_salaries = new int[num_employee];

	for (int i = 0; i < num_employee; ++i)
		cin >> employee_salaries[i];

	// delete it
	delete[] employee_salaries;

	// =================== Array of Pointers ==============================

	int *arr[3] = {0};

	for (int i = 0; i < 3; ++i)
		arr[i] = new int[2];	//pointer 2 elements

	// now arr are represented as normal array 3x2 in memory
	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 2; ++j)
			arr[i][j] = i*2+j;

	// to delete this array
	for (int i = 0; i < 3; ++i)
		delete[] arr[i];

	//======================Pointer Of Pointer ===========================
	int **ptrarr = create();
	free(ptrarr);


	return 0;
}
