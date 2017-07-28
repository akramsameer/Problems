#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
#define isPowerOfTwo(S) (!(S & (S - 1)))
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
#define f first
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int cnt = 1;
map<string, int> mp;
void solve(int ind, string temp, int k) {
	if (sz(temp) == k) {
		mp[temp] = cnt++;
		return;
	}
	for (int i = ind + 1; i < 26; i++){
		temp.push_back('a' + i);
		solve(i, temp, k);
		temp.erase(temp.end() -1);
	}
}

set<int> st;
int main() {
	file();
	for (int i = 1; i <= 5; i++)
		solve(-1, "", i);
	string temp;
	while (cin >> temp) {
		if (mp.find(temp) != mp.end())
			printf("%d\n", mp[temp]);
		else
			printf("0\n");
	}
	return 0;
}

