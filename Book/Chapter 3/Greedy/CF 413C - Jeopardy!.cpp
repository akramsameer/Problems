#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
#define isPowerOfTwo(S) (!(S & (S - 1)))
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
#endif
}
int n, m, idx[100 + 9];
ll arr[100 + 9];
bool au[100 + 9];

bool cmp(int a, int b) {
	if (!au[a] && au[b])
		return 1;
	if (au[a] && au[b])
		return arr[a] > arr[b];

	return 0;
}

int main() {
	file();
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		idx[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		au[x - 1] = 1;
	}
	sort(idx, idx + n, cmp);
	ll sum = 0;
	for (int i = 0; i < n - m; i++)
		sum += arr[idx[i]];

	for(int i = n-m ; i < n ; i++){
		if(sum > arr[idx[i]])
			sum += sum;
		else
			sum += arr[idx[i]];
	}
	cout<<sum<<endl;
	return 0;
}
