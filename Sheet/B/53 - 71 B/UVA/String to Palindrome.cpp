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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
int t, mem[1001][1001], ca = 1;
string arr;
int solve(int ind1, int ind2) {
	if (ind1 >= ind2)
		return 0;

	int& ret = mem[ind1][ind2];

	if (ret != -1)
		return ret;

	if (arr[ind1] == arr[ind2])
		ret = solve(ind1 + 1, ind2 - 1);
	else
		ret = min(solve(ind1 + 1, ind2),
				min(solve(ind1, ind2 - 1), solve(ind1 + 1, ind2 - 1)))+1;
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin>>arr;
		clr(mem, -1);
		int res = solve(0, sz(arr) - 1);
		cout << "Case " << ca++ << ": " << res << endl;
	}
	return 0;
}
