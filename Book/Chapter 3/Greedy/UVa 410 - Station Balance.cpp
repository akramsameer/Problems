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
int arr[20], ans[20], tot, c, s, lineCounter = 1;
double diff, av;
int main() {
	file();
	bool fi = 1;
	while (scanf("%d %d", &c, &s) != EOF) {
		diff = 0, tot = 0;
		if (!fi)
			printf("\n");
		fi = 0;
		for (int i = 0; i < s; i++) {
			cin >> arr[i];
			tot += arr[i];
		}
		for (int i = s; i < 2 * c; i++)
			arr[i] = 0;
		av = tot * 1.0 / c * 1.0;
		sort(arr, arr + (2 * c));
		printf("Set #%d\n", lineCounter++);

		int j = ((2 * c) / 2) - 1;
		for (int i = (2 * c) / 2; i < 2 * c; i++ , j--) {
			printf(" %d: ", i);
			if (arr[j] != 0)
				printf("%d ", arr[j]);
			printf("%d", arr[i]);
			printf("\n");
			diff += abs((av - (arr[j] + arr[i])));
		}

		printf("IMBALANCE = %0.5lf\n", diff);
	}
	return 0;
}
