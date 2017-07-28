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

int main() {
	file();
	int n;
	while (cin >> n , n) {
		getchar();
		int * arr = new int[n];
		int mi = OOI;
		for (int i = 0; i < n; i++) {
			string temp;
			getline(cin, temp);
			int sum = 0;
			for (int j = 0; j < sz(temp); j++)
				if (temp[j] == ' ')
					sum++;

			arr[i] = sum;
			mi = min(arr[i], mi);
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += arr[i] - mi;

		cout << ans << endl;
	}
	return 0;
}

