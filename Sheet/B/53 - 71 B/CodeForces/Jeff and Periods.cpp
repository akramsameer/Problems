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
int arr[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	vi vec[100001];
	vii ans;
	for (int i = 1; i <= n; i++) {
		vec[arr[i]].push_back(i);
	}

	int res = 0;
	for (int i = 1; i <= 100000; i++) {
		int diff = -1;
		bool flag = 1;
		for (int j = 1; j < sz(vec[i]); j++) {
			if (diff != -1) {
				if (vec[i][j] - vec[i][j - 1] != diff)
					flag = false;
			} else
				diff = vec[i][j] - vec[i][j - 1];
		}
		if (diff == -1 && sz(vec[i]) > 0) {
			ans.push_back(make_pair(i, 0));
			res++;
		} else if (flag && sz(vec[i]) > 0) {
			ans.push_back(make_pair(i, diff));
			res++;
		}
	}

	cout << res << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << endl;
	return 0;
}
