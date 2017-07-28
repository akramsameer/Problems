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
string arr;
int mem[101][1001][2];

bool solve(int ind = 0, int sum = 0 , bool flag = 0) {
	if (sum % 8 == 0 && flag) {
			cout<<"YES"<<endl;
			cout << sum << endl;
			return 1;
		}

	if (ind >= sz(arr) || sum >= 1000)
		return 0;



	int& ret = mem[ind][sum][flag];
	if (ret != -1)
		return ret;

	ret = solve(ind + 1, sum , flag) || solve(ind + 1, (sum * 10) + (arr[ind] - '0') , 1);
	return ret;
}

int main() {
	file();
	clr(mem, -1);
	cin >> arr;
	if(!solve())
		cout<<"NO"<<endl;


	return 0;
}

