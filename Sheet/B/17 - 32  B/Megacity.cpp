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
struct node {
	int x, y, val;
	double dis;
	bool operator <(const node &e) const {
		return dis < e.dis;
	}
};
int n, s;
node arr[1001];
double dis[1001];
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y >> arr[i].val;

	for (int i = 0; i < n; i++) {
		arr[i].dis = sqrt(pow(arr[i].x, 2) + pow(arr[i].y, 2));
	}
	sort(arr, arr + n);

	double ans = 0;
	for (int i = 0; i < n; i++) {
		s += arr[i].val;
		if (s >= 1000000) {
			ans = arr[i].dis;
			break;
		}
	}
	if (ans == 0.00)
		cout << -1 << endl;
	else
		cout << fixed << setprecision(7) << ans << endl;
	return 0;
}

