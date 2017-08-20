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
int n, len, vis[26], cnt;
double sum, p[] = { 12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25,
		0.44, 0.00, 4.97, 3.15, 6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93,
		0.90, 0.02, 0.22, 0.90, 0.52 };
string odd = "bcdfghjklmnpqrstvwxyz", even = "aeiou";
char word[10];
void solve(int ind, double val) {
	if (ind == len) {
		sum += val;
		cnt++;
		return;
	}
	if (ind % 2 == 1) {
		for (int i = 0; i < sz(even); i++)
			if (vis[even[i] - 'a'] < 2) {
				vis[even[i] - 'a']++;
				solve(ind + 1, val + ((ind + 1) * p[even[i] - 'a']));
				vis[even[i] - 'a']--;
			}

	} else {
		for (int i = 0; i < sz(odd); i++) {
			if (vis[odd[i] - 'a'] < 2) {
				vis[odd[i] - 'a']++;
				solve(ind + 1, val + ((ind + 1) * p[odd[i] - 'a']));
				vis[odd[i] - 'a']--;
			}
		}
	}
}
double sbc() {
	double ret = 0;
	for (int i = 0; i < len; i++)
		ret += (i + 1) * p[word[i] - 'a'];
	return ret;
}

int main() {
	file();
	scanf("%d", &n);
	while (n--) {
		scanf("%s", word);
		len = strlen(word);
		cnt = sum = 0;
		clr(vis, 0);
		solve(1, p[word[0] - 'a']);
		double res = sum / cnt;
		if (sbc() >= res)
			printf("above or equal\n");
		else
			printf("below\n");
	}
	return 0;
}
