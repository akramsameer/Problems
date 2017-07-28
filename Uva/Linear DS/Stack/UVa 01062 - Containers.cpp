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
string str ;
int cas = 1 , ans  = 0 ;
vector< stack<char> > s;
stack<char> e;
int main() {
	file();
	while(cin >> str){
		if(str == "end")
			break;

		s.clear();
		s.push_back(e);
		s[0].push(str[0]);
		ans = 1;
		for(int i = 1 ; i < sz(str) ; i++)
		{
			bool f = 0;
			for(int j = 0 ; j < sz(s) ; j++)
				if(s[j].top() >= str[i] ){
					s[j].push(str[i]);
					f = 1;
					break;
				}
			if(!f){
				s.push_back(e);
				s[sz(s)-1].push(str[i]);
				ans++;
			}

		}
		printf("Case %d: %d\n" , cas++ , ans);
	}
	return 0;
}

