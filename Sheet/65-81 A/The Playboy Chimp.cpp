#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
int n, q;
ll arr[50001];
pair<ll, ll> solve(ll val) {
	int s = 0, e = n-1, ans = -1, mid ;
	pair<ll, ll> ret;
	while (s <= e) {
		mid = (s + e) / 2;
		if (arr[mid] < val) {
			ans = mid;
			s = mid + 1;
		} else
			e = mid - 1;
	}
	if (ans == -1)
		ret.first = ans;
	else
		ret.first = arr[ans];

	int ind = ans+1	;
	while (ind < n && arr[ind] == val) {
		ind++;
	}
	if (ind >= n)
		ret.second = -1;
	else
	ret.second = arr[ind];

	return ret;
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	cin >> q;
	for (int i = 0; i < q; ++i) {
		ll x;
		cin >> x;
		pair<ll, ll > ans = solve(x);
		if (ans.first == -1)
			cout << "X ";
		else
			cout << ans.first << " ";
		if (ans.second == -1)
			cout << "X\n";
		else
			cout << ans.second << "\n";
	}
	return 0;
}
