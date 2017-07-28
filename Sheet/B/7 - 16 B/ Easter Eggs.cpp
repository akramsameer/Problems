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
int n;
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	string ans = "";
	for (int i = 0; i < n / 7; ++i) {
		ans += "ROYGBIV";
	}
	int rem = n % 7;

	//"G", "GB", "YGB", "YGBI", "OYGBI" or "OYGBIV"
	switch (rem) {
	case 1:
		ans += "G";
		break;

	case 2:
		ans += "GB";
		break;

	case 3:
		ans += "YGB";
		break;

	case 4:
		ans += "YGBI";
		break;

	case 5:
		ans += "OYGBI";
		break;

	case 6:
		ans += "OYGBIV";
		break;

	}
	cout << ans << endl;
	return 0;
}

