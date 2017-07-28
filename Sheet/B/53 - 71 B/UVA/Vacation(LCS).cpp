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
string x, y;
int mem[101][101];
int solve(int ind1 , int ind2){
	if(ind1 == sz(x) || ind2 == sz(y))
		return 0;

	int& ret = mem[ind1][ind2];

	if(ret != -1)
		return ret;

	if(x[ind1] == y[ind2])
		ret = 1 + solve(ind1 +1 , ind2 +1);
	else
		ret = max (solve(ind1+1 , ind2) , solve(ind1 , ind2 +1));

	return ret;
}
int main() {
	freopen("in.txt", "r", stdin);
	int cas = 1;
	while (getline(cin, x)) {
		if (x == "#")
			break;
		getline(cin, y);
		clr(mem , -1);
		int res = solve(0, 0);
		cout << "Case #" << cas++ << ": you can visit at most " << res
				<< " cities." << endl;
	}

	return 0;
}
