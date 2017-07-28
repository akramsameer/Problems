#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
#define f first
#define s second
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
int n, arr[100000 + 9], H[100000 + 9], mem[100000 + 9][3];

int solve(int ind = 0, int dir = 2) {
	if (ind >= n)
		return 0;

	int &ret = mem[ind][dir];
	if (ret != -1)
		return ret;

	int sol1 = 0, sol2 = 0, sol3 = 0;
	if (ind == 0 || (arr[ind] - H[ind] > arr[ind - 1] && (dir != 1))				// fall right
			|| (arr[ind] - H[ind] > arr[ind - 1] + H[ind - 1] && dir == 1))
		sol1 = solve(ind + 1, 0) + 1;

	if (ind == 0 || ind == n - 1 || (arr[ind] + H[ind] < arr[ind + 1]))			//fall right
		sol2 = solve(ind+1 , 1) + 1;

	sol3 = solve(ind+1 , 2);

	ret = max(sol1 , max(sol2 , sol3));
	return ret;
}

int main() {
	file();
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i] >> H[i];
	clr(mem , -1);
	cout << solve() << endl;
	return 0;
}

