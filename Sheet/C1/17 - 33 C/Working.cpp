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

int main() {
	file();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		printf("%d ", i);
	printf("\n");
	for(int i = n -1 ; i >= 0 ;i--)
		if(!(i&1))
			printf("%d " , i);

	for (int i = n - 1; i >= 0; i--)
		if (i & 1)
			printf("%d ", i);

	printf("\n");
	for(int i = n-1 ; i >= 0 ;i--)
		printf("%d ", i);

	printf("\n");
	return 0;
}

