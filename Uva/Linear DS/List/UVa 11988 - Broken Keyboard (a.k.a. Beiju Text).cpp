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
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}

int main() {
	file();
	string str;
	while (cin >> str) {
		list<char> lst;
		list<char>::iterator it = lst.begin();
		for(int i = 0 ; i < sz(str) ; i++){
			if(str[i] == '[')
				it = lst.begin();
			else if(str[i] == ']')
				it = lst.end();
			else
				lst.insert(it , str[i]);
		}

		for(it = lst.begin(); it != lst.end() ; it++)
			printf("%c" , *it);
		printf("\n");
	}
	return 0;
}

