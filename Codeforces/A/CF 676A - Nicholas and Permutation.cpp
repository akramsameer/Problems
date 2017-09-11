#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
#define EPS 1e-9
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int n;
int arr[101];

int main() {
	file();
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int mx_pos = max_element(arr, arr + n) - arr;
	int mn_pos = min_element(arr, arr + n) - arr;
	if (abs(mx_pos - mn_pos) == n - 1)
		printf("%d\n", n - 1);
	else {
		printf("%d\n",
				max(abs(n - 1 - mn_pos),
						max(abs(0 - mn_pos),
								max(abs(n - 1 - mx_pos), abs(0 - mx_pos)))));
	}
	return 0;
}

