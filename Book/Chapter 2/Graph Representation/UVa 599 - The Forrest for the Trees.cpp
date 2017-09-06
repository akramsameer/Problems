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
bool vis[26];
int t;
string temp;
int main() {
	file();
	cin >> t;
	while(t--){
		clr(vis , 0);
		int edge = 0 , ac = 0 , v = 0;
		while(cin >> temp){
			if(temp[0] == '*')
				break;
			char c1 = temp[1];
			char c2 = temp[3];
			vis[c1 - 'A'] = 1;
			vis[c2 - 'A'] = 1;
			edge++;
		}

		cin >> temp;
		for(int i = 0 ; i < sz(temp); i+=2){
			if(!vis[temp[i] - 'A'])
				ac++;
			else
				v++;
		}
		int ans = v - edge;
		printf("There are %d tree(s) and %d acorn(s).\n" , ans , ac);
	}
	return 0;
}
