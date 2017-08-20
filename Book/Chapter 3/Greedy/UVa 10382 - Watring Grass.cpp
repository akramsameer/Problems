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
int L, W, n;
struct sprinklers {
	double st, en;
} arr[10000 + 9];

bool cmp(sprinklers a, sprinklers b) {
	if (a.st == b.st)
		return a.en > b.en;
	else
		return a.st < b.st;
}

int main() {
	file();
	while (scanf("%d %d %d", &n, &L, &W) != EOF) {
		int m = 0;
		for (int i = 0; i < n; i++) {
			double pos, rad;
			cin >> pos >> rad;
			if (rad > W / 2.0) {
				double dx = sqrt(rad * rad - (W / 2.0) * (W / 2.0));
				arr[m].st = pos - dx;
				arr[m++].en = pos + dx;
			}
		}

		sort(arr, arr + m, cmp);

		double prev_en = 0.0;
		int count = 0;
		for (int i = 0; i < m; i++) {
			if(arr[i].st > prev_en)
				break;

			for(int j = i+1 ; j < m && arr[j].st <= prev_en ;j++){
				if(arr[j].en > arr[i].en)
					i = j;
			}

			prev_en = arr[i].en;
			count++;
			if(prev_en >= L)
				break;
		}
		if (prev_en >= L)
			printf("%d\n", count);
		else
			printf("-1\n");
	}
	return 0;
}
