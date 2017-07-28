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
const ll M = 10000000;
bool prime[M + 9];

int main() {
	file();
	prime[0] = prime[1] = 1;
	for (int i = 2; i <= M; i++) {
		if (!prime[i])
			for (int j = i * 2; j <= M; j += i)
				prime[j] = 1;
	}

	ll n;
	while (cin >> n) {
		if(n < 8){
			cout<<"Impossible."<<endl;
			continue;
		}

		if (n & 1) {
			cout << "2 3 ";
			n -= 5;
		} else {
			cout << "2 2 ";
			n -= 4;
		}

		int i ;
		for (i = 2; i < n; i++)
			if (!prime[i] && !prime[n - i]) {
				cout << i << " " << n - i << endl;
				break;
			}


	}

	return 0;
}

