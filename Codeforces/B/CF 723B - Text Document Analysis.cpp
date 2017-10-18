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
const double PI = acos(-1.0);
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int ydir[] = { 0, 1, -1, 1, -1, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int n  , mx , num , cur;
bool in = false;
char c;
int main() {
	file();
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		cin >> c ;
		if(c == '('){
			in = 1 ;
			cur = 0;
		}
		else if (c == ')'){
			in = 0;
			if(cur != 0)
				num++;
			cur = 0;
		}
		else if(c == '_' ){
			if(in and cur != 0)
				num++;
			cur = 0;
		}
		else {
			if(!in){
				cur += 1;
				mx = max(mx , cur);
			}
			else{
				cur +=1;
			}
		}
	}
	printf("%d %d\n", mx , num);

	return 0;
}
