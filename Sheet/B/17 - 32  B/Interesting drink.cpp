#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
int n, arr[100001], q;
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cin >> q;

	sort(arr, arr + n);

	for (int i = 0; i < q; i++) {
		int temp;
		cin >> temp;

		int st = 0, en = n - 1;
		int mid = 0;

		while (st <= en) {
			mid = (st + en) / 2;
			if (arr[mid] <= temp)
				st = mid + 1;
			else
				en = mid - 1;
		}

		cout << st << endl;
	}

	return 0;
}
