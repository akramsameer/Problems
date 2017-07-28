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
int m, s, mx = -1000, mi = 1000;
pair<string, string> mem[100 + 9][1000 + 9];
int tot(int x) {
	int ret = 0;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

pair<string, string> solve(int len, int sum) {
	if (sum < 0)
		return make_pair("-1", "-1");

	if (len == m) {
		if (sum == 0) {
			return make_pair("", "");
		}
		return make_pair("-1", "-1");
	}

	pair<string, string>& ret = mem[len][sum];

	if (ret.f != "-1")
		return ret;

	pair<string, string> k = make_pair("-11", "-11");

	for (int i = (len == 0) ? 1 : 0; i < 10; i++) {
		pair<string, string> ans = solve(len + 1, sum - i);
		if (ans.f == "-1" || ans.f == "-11")
			continue;
		stringstream ss;
		ss << i;
		k.f = ss.str() + ans.f;
		if (k.s == "-11")
			k.s = ss.str() + ans.s;

	}

	return ret = k;
}
int main() {
	file();
	cin >> m >> s;

	for (int i = 0; i < 109; i++)
		for (int j = 0; j < 1009; j++)
			mem[i][j].f = mem[i][j].s = "-1";


	if (m == 1 && s == 0){
		cout<<"0 0"<<endl;
		return 0;
	}
	pair<string, string> ans = solve(0, s);

	if (ans.f == "-11")
		cout << "-1 -1" << endl;
	else
		cout << ans.s << " " << ans.f << endl;
	return 0;
}

