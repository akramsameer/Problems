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
int xdir[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int ydir[] = { 0, 1, -1, 1, -1, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}

int main() {
	file();
	string a, b;
	while (getline(cin, a)) {
		getline(cin, b);
		vector<int> visa(26, 0), visb(26, 0);
		for (int i = 0; i < sz(a); i++)
			visa[a[i] - 'a']++;
		for (int i = 0; i < sz(b); i++)
			visb[b[i] - 'a']++;

		for (int i = 0; i < 26; i++) {
			if (visa[i] && visb[i])
				for (int j = 0; j < min(visa[i], visb[i]); j++)
					cout << char(i + 'a');
		}
		printf("\n");
	}

	return 0;
}

