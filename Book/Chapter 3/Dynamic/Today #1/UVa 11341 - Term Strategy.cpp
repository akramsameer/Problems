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
const double PI = acos(-1.0);
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int tc, n, m;
int arr[10 + 9][100 + 9];
int mem[10 + 9][100 + 9];
int solve(int ind, int rem) {
	if (ind >= n)
		return 0;
	if(rem <= 0)
		return -OOI;
	int &ret = mem[ind][rem];
	if (ret != -1)
		return ret;
	ret = -OOI;
	for (int i = 0; i < m; i++)
		if (rem - (i + 1) >= 0 && arr[ind][i] >= 5.0)
			ret = max(ret, solve(ind + 1, rem - (i + 1)) + arr[ind][i]);
	return ret;
}

int main() {
	file();
	cin >> tc;
	while (tc--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> arr[i][j];
		clr(mem, -1);
		int sum = solve(0, m);
		double avg = sum * 1.0 / n * 1.0;
		if (avg >= 5.0)
			printf("Maximal possible average mark - %0.2lf.\n", avg + EPS);
		else
			printf("Peter, you shouldn't have played billiard that much.\n");
	}
	return 0;
}

