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
#endif
}
void CountSort(int arr[], int n , int L , int R) {

	vi output = vi(n+9);

	int k = (R - L) +1;

	vi count = vi(k, 0);

	for (int i = 0; i < n; i++)
		count[arr[i] - L]++;

	for (int i = 1; i < k; i++)
		count[i] += count[i - 1];

	for(int i =0 ; i < n ; i++){
		output[count[arr[i] - L] -1] = arr[i];
		count[arr[i] - L]--;
	}

	for(int i = 0 ; i < n ; i++)
		arr[i] = output[i];
}

int main() {
	file();
	int arr[2000000 + 9], n;
	while (scanf("%d\n", &n) && n) {
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);

		CountSort(arr, n , 1 , 101);
		for (int i = 0; i < n - 1; i++)
			printf("%d ", arr[i]);
		printf("%d\n", arr[n - 1]);
	}
	return 0;
}
