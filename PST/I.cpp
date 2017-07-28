#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
int t;
int n, k, arr[27];
string s[110];
string ans[110];
int main() {
	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--) {

		cin >> n >> k;
		for (int i = 0; i < 26; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++)
			cin >> s[i];

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			int sum = 0;
			for (int j = 0; j < s[i].size(); ++j) {
				int ind = s[i][j] - 'a';
				sum += arr[ind];
			}
			if (sum >= k)
				cout<<s[i]<<endl;
		}
	}

	return 0;
}
