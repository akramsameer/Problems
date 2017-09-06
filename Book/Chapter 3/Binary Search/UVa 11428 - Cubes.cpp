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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int main()
{
	file();
	int j, i, n, flag;
	while (cin >> n , n) {
		flag = 0;
		for (i = 1; i < 60; i++) {
			for (j = 0; j <= i; j++) {
				if ((i * i * i - j * j * j) == n) {
					printf("%d %d\n", i, j);
					flag = 1;
					break;
				}
			}
			if (flag == 1)
				break;
		}
		if (i == 60)
			printf("No solution\n");
	}
	return 0;
}
