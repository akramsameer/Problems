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
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int g, money, k, tc, m, c;
int price[25][25];
bool reachable[25][210];

int main() {
	file();
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &m, &c);
		for (g = 0; g < c; g++) {
			scanf("%d", &price[g][0]);
			for (money = 1; money <= price[g][0]; money++)
				scanf("%d", &price[g][money]);
		}
		clr(reachable, 0);
		for (g = 0; g <= price[0][0]; g++)
			if (m - price[0][g] >= 0)
				reachable[0][m - price[0][g]] = true;			//first garment

		for (g = 1; g < c; g++) {
			for (money = 0; money <= m; money++) {
				if (reachable[g - 1][money])
					for (k = 1; k <= price[g][0]; k++)
						if (money - price[g][k] >= 0)
							reachable[g][money - price[g][k]] = 1;
			}
		}

		for(money = 0 ; money <= m && !reachable[c-1][money] ; money++);

		if(money == m+1)	printf("no solution\n");
		else 				printf("%d\n" , m - money);
	}

	return 0;
}
