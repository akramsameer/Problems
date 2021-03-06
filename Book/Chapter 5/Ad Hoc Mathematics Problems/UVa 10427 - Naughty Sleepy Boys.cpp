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
int xdir[] = { 1, -1, 0, 0 };
;
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int main() {
	file();
	ll n;
	while (cin >> n) {
		n--;
		int a = 1, k = 1;
		while(n >= a * 9 * k){ 	// 9 - 99 - 999 ...
			n -= a * 9 * k;		// find position
			a *=10;
			k++;	// number of blocks;
		}
		int x = n / k;		//find the number which contain n'th number
		int num = a + x;	// start block + number = the real number

		n = k - (n % k) -1;		// n % k ==> digit number

		while(n-- > 0)
			num /=10;
		num %= 10;
		printf("%d\n" , num);

	}
	return 0;
}

