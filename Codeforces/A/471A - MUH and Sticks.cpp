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
int li[10], arr[6];
int main() {
	file();
	for (int i = 0; i < 6; i++) {
		cin >> arr[i];
		li[arr[i]]++;
	}
	bool f = 0, t = 0;
	for (int i = 1; i < 10; i++) {
		if (li[i] == 4)
			f = 1;
		if (li[i] == 2)
			t = 1;
		if (li[i] == 6)
			f = t = 1;
		if (li[i] == 5)
			f = 1;
	}
	if (f && t)
		cout << "Elephant\n";
	else if (f && !t)
		cout << "Bear\n";
	else
		cout << "Alien\n";

	return 0;

}
