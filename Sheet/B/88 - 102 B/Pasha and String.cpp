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
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
int com[100001], arr[100001];
int main() {
	file();
	string str;
	cin >> str;
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		com[arr[i] - 1]++;
	}

	for (int i = 1; i < (sz(str) + 1) / 2; i++)
		com[i] += com[i - 1];

	for (int i = 0; i <= (sz(str) + 1) / 2; i++)
		if (com[i] & 1)
			swap(str[i], str[sz(str) - i - 1]);

	cout<<str<<endl;

	return 0;
}

