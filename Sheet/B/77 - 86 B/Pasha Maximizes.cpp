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

int main() {
	file();
	string str;
	int k;
	cin >> str >> k;

	int mx_pos = -1;
	for (int i = 0; i < sz(str) && k; i++) {
		int mx = -1;
		for (int j = i; j < sz(str) && k - (j - i) >= 0; j++)
			if (mx_pos == -1 || (str[j] > mx )) {
				mx_pos = j;
				mx = str[j];
				if (k - (j - i) <= 0)
					break;
			}

		int ind = mx_pos;
		while (k > 0 && ind >= 1 && str[ind] > str[ind - 1]) {
			swap(str[ind], str[ind - 1]);
			ind--;
			k--;
		}
	}

	cout << str << endl;
	return 0;
}

