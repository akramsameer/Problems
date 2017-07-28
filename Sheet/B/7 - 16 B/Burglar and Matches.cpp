#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
ll n;
int m;
pair<ll, ll> arr[21];

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
	if (b.first < a.first) {
		return true;
	}
	else if (b.first == a.first){
		return b.second < b.first;
	}
	else
		return false;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
		cin >> arr[i].second >> arr[i].first;

	sort(arr, arr + m, cmp);
	ll output = 0;
	for (int i = 0; i < m && n; ++i) {
		if (arr[i].second <= n) {
			output += arr[i].second * arr[i].first;
			n -= arr[i].second;
		} else {
			output += (n * arr[i].first);
			n = 0;
		}
	}
	cout << output << endl;

	return 0;
}

