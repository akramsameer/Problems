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
int xdir[] = { 1, -1, 0, 0 };
;
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
set<int> st;
int n, m, k;
ll arr[19];
string solve (int x , int n) {
	string ret = "";
	while(x) {
		int rem = x % n;
		ret.push_back(rem + '0');
		x = x / n;
	}
	reverse(ret.begin() , ret.end());
	return ret;
}
int main() {
	file();
	int k;
	cin >> k;
	for (int i = 1; i < k;printf("\n"), ++i)
		for (int j = 1; j < k; printf(" "), ++j) {
			cout << solve(i * j, k);
		}


	return 0;
}

