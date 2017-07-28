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

int main() {
	file();
	int t, cas = 1;
	cin >> t;
	while (t--) {
		int n, m;
		map<int, int> mp;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> m;
			;
			for (int j = 0; j < m; j++) {
				int x;
				cin >> x;
				if (mp.find(x) == mp.end())
					mp[x] = i;
				else {
					if (mp[x] != i)
						mp[x] = -1;
				}
			}
		}

		vector<int> ans = vector<int>(n, 0);
		int siz = 0;
		for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it++) {
			if ((*it).second != -1) {
				ans[it->second]++;
				siz++;
			}
		}

		printf("Case %d: ", cas++);
		for (int i = 0; i < n; i++) {
			double x = (ans[i] * 1.0 / siz * 1.0) * 100;
			printf("%.6lf", x);
			if (i != n - 1)
				cout << "% ";
			else
				cout<< "%";
		}
		printf("\n");
	}
	return 0;
}

