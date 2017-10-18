#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
#define EPS 1e-9
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
const double PI = acos(-1.0);
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int ydir[] = { 0, 1, -1, 1, -1, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int f[26], B[26], C[26];
string a, b, c;

int main() {
	file();
	cin >> a >> b >> c;
	for (int i = 0; i < sz(a); i++)
		f[a[i] - 'a']++;
	for (int i = 0; i < sz(b); i++)
		B[b[i] - 'a']++;
	for (int i = 0; i < sz(c); i++)
		C[c[i] - 'a']++;

	int mn = OOI;

	for (int i = 0; i < sz(b); i++) {
		int ch = b[i] - 'a';
		if (B[ch] <= f[ch])
			mn = min(mn, f[ch] / B[ch]);
		else {
			mn = OOI;
			break;
		}
	}

	for (int i = 0; i < sz(b) and mn != OOI; i++) {
		int ch = b[i] - 'a';
		f[ch] -= (mn * B[ch]);

	}
//	int dd  = 0;
//		for(int i = 0 ; i < 26 ; i++)
//			dd += f[i];
//		cout<<dd<<endl;

	while (mn && mn != OOI)
		cout << b, mn--;

	mn = OOI;
	for (int i = 0; i < sz(c); i++) {
		int ch = c[i] - 'a';
		if (C[ch] <= f[ch])
			mn = min(mn, f[ch] / C[ch]);
		else{
			mn = OOI;
			break;
		}
	}

	for(int  i = 0 ; i < sz(c) && mn != OOI ; i++)
		f[c[i] -'a'] -= mn * C[c[i] - 'a'];

	while (mn && mn != OOI)
		cout << c, mn--;

	for (int i = 0; i < sz(a); i++) {
		int ch = a[i] - 'a';
		if (f[ch] > 0)
			while (f[ch])
				cout << a[i], f[ch]--;
	}
	printf("\n");

#ifndef ONLINE_JUDGE
	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
