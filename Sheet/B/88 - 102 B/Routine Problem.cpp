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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
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
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int p1 = (b * c - a * d), q1 = b * c;
	int p2 = (a * d - b * c), q2 = a * d;

	if(p1> 0){
		int g = __gcd(p1 , q1);
		printf("%d/%d\n" , p1/g , q1/g);
	}
	else
	{
		int g = __gcd(p2 , q2);
		printf("%d/%d\n" , p2/g , q2/g);
	}
	return 0;
}

