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
double  r1, p1, p2, x[5001], y[5001], z[5001], a, b;
int n, m, k;
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> x[i];

	cin >> m;
	for (int i = 0; i < m; i++)
		cin >> y[i];

	cin >> k;
	for (int i = 0; i < k; i++)
		cin >> z[i];

	cin >> a >> b;

	sort(x, x + n);
	sort(y, y + m);
	sort(z, z + k);

	cout<<fixed <<setprecision(12) << (x[n - 1] * sqrt((b * y[m - 1]) / (a * z[0] + b * y[m - 1])));
	return 0;
}
