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

int n, arr[1001], mx;
int solve(int ind) {
	int ret = 1;
	int right = ind + 1;
	int prevright = ind , prevleft = ind;
	int left = ind - 1;

	while (left >= 0 && arr[left] <= arr[prevleft]) {
		ret++;
		prevleft = left;
		left--;
	}
	while (right < n &&arr[right] <= arr[prevright]) {
		ret++;
		prevright = right;
		right++;
	}
	return ret;
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		int lomx = solve(i);
		if (mx < lomx)
			mx = lomx;
	}

	cout << mx << endl;
	return 0;
}

