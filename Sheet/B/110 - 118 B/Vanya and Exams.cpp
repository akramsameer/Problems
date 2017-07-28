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
#define s second
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
pair<ll, ll> arr[100000 + 9];
ll r, avg, steps, k, n, sum;

int main() {
	file();
	cin >> n >> r >> avg;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].s >> arr[i].f;
		sum += arr[i].s;
	}

	k = (avg - (ceil(sum*1.00 / n))) * n;

	if (ceil(sum*1.00 / n) != floor(sum*1.00 / n))
		k += n - (sum % n);

	sort(arr, arr + n);

	for (int i = 0; i < n && k > 0 ; i++) {
		ll rem = r - arr[i].s;
		ll ma = min(rem , k);
		steps += ma * arr[i].f;

		k-=ma;
	}
	cout<<steps<<endl;
	return 0;
}

