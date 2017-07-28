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
int n, arr[51];
int main() {
	freopen("in.txt", "r", stdin);
	while (cin >> n) {
		if (!n)
			break;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int count = 0, npaires = 0;
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n; j++) {
				if (__gcd(arr[i], arr[j]) == 1)
					count++;

				npaires++;
			}
		}
		if (!count) {
			cout << "No estimate for this data set." << endl;
			continue;
		}
		double ans = sqrt((((double)6 * npaires) / count));
		cout<<fixed<<setprecision(6)<<ans<<endl;
	}

	return 0;
}
