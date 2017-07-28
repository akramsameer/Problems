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
string str;
char h[] = { 'h', 'e', 'a', 'v', 'y' };
char m[] = { 'm', 'e', 't', 'a', 'l' };

bool heavy(int ind) {
	if (ind + 5 > sz(str))
		return false;

	for (int i = 0; i < 5; i++)
		if (str[i + ind] != h[i])
			return false;

	return 1;
}

bool metal(int ind) {
	if (ind + 5 > sz(str))
		return false;

	for (int i = 0; i < 5; i++)
		if (str[i + ind] != m[i])
			return false;
	return 1;
}

int main() {
	file();

	cin >> str;
	int he = 0;
	int res = 0;
	for (int i = 0; i < sz(str); i++) {
		if (heavy(i)) {
			he++;
			i += 4;
		} else if (metal(i)) {
			res += he;
			i += 4;
		}
	}
	cout << res << endl;
	return 0;
}
