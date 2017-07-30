#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
#define isPowerOfTwo(S) (!(S & (S - 1)))
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
#define f first
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}

void Merge(vi& arr, int left, int mid, int right, int& cnt) {
	int n1 = mid - left, n2 = right - mid;
	vi L, R;
	for (int i = 0; i < n1; i++)
		L.push_back(arr[left + i]);
	for (int i = 0; i < n2; i++)
		R.push_back(arr[mid + i]);
	L.push_back(INT_MAX);
	R.push_back(INT_MAX);
	int i = 0, j = 0;
	for (int k = left; k < right; k++) {
		if(L[i] <= R[j])
			arr[k] = L[i++];
		else{
			arr[k] = R[j++];
			cnt += (n1 - i);
		}
	}
}

void MergeSort(vi& arr, int left, int right, int& count) {
	if (left >= right - 1)
		return;
	int mid = (right + left) / 2;
	MergeSort(arr, left, mid, count);
	MergeSort(arr, mid, right, count);
	Merge(arr, left, mid, right, count);
}
int main() {
	file();
	int n;
	while (cin >> n) {
		vi arr = vi(n);
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int cnt = 0;
		MergeSort(arr, 0, n, cnt);
		printf("Minimum exchange operations : %d\n" , cnt);
	}
	return 0;
}

