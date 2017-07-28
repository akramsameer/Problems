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
void solve(char c, vi & left, vi& right, vector<bool>&flag) {

	if (c == '=')
		for (int i = 0; i < sz(left); i++)
			flag[left[i]] = flag[right[i]] = 1;

//	else if (c == '<')
//		for (int i = 0; i < sz(left); i++)
//			flag[left[i]] = 1;
//	else
//		for (int i = 0; i < sz(right); i++)
//			flag[right[i]] = 1;
}
int main() {
	file();
	int t;
	cin >> t;
	while (t--) {
		int n, k, p;
		vector<bool> flag = vector<bool>(100 + 9, false);
		cin >> n >> k;

		while (k--) {
			vi left, right;
			cin >> p;
			for (int i = 0; i < p; i++) {
				int x;
				cin >> x;
				left.push_back(x);
			}

			for (int i = 0; i < p; i++) {
				int x;
				cin >> x;
				right.push_back(x);
			}

			char c;
			cin >> c;
			solve(c, left, right, flag);
		}

		int ind = -1 , cnt = 0;
		for (int i = 1; i <= n; i++) {
			if(!flag[i]){
				ind = i ;
				cnt ++;
			}
		}

		printf("%d\n" , (cnt == 1) ? ind : 0);
		if (t)
			printf("\n");
	}
	return 0;
}

