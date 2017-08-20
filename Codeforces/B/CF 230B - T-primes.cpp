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
const int MAXINT = 1000000 +9;
int n ;
bool prime[MAXINT];

void sieve(){
	prime[0] = prime[1] = 0;

	for(int i = 2 ; i < sqrt(MAXINT) ; i++)
		for(int j = i*i  ; j < MAXINT ; j+=i)
			prime[j] = 0;

}
int main() {
	file();
	cin >> n;
	clr(prime , 1);
	sieve();
	for(int i = 0 ; i < n ; i++)
	{
		ll x;
		cin >> x;
		if(floor(sqrt(x)) == ceil(sqrt(x))){
			if(prime[int(sqrt(x))])
			cout<<"YES\n";
		else
			cout<<"NO\n";
		}
		else
			cout<<"NO\n";
	}
	return 0;
}
