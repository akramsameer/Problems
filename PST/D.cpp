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
int t, n, vis[8][8], arr[8];
int main() {
	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			arr[i] = i;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> vis[i][j];
		int m = OOI;
		do {
			int sum = 0;
			for (int i = 0; i < n-1 ; ++i)
				if (!vis[arr[i]][arr[i+1]])
					sum++;

			m = min(m, sum);

		} while (next_permutation(arr, arr + n));

		cout << m << endl;
	}

	return 0;
}
