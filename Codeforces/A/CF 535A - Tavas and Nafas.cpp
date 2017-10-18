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
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int s;
string number[30] { "", "one", "two", "three", "four", "five", "six", "seven",
		"eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
		"fifteen", "sixteen", "seventeen", "eighteen", "nineteen" }, dd[20] {
		 "", "", "twenty", "thirty", "forty", "fifty", "sixty","seventy" ,"eighty",
		"ninety" };

int main() {
	file();
	cin >> s;
	if (s < 20)
		cout << number[s] << endl;
	else {
		int x = (s / 10);
		if (s % 10 == 0)
			cout << dd[s / 10] << endl;
		else
			cout << dd[x] << "-" << number[s % 10] << endl;
	}
	return 0;
}

