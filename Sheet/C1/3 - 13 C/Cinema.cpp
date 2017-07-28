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
#define s second
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
int n  , m;
map<ll , int > mp;
ll au[200000+9] , su[200000+9];
int main() {
	file();
	cin >> n ;
	for(int i = 0 ; i < n ; i++){
		int x ;
		cin >> x;
		if(mp.find(x) == mp.end())
			mp[x] = 1;
		else
			mp[x]++;
	}
	cin >> m ;
	for(int i = 0  ; i< m ;i++)
		cin >> au[i];
	for(int i = 0 ; i < m ;i++)
		cin >> su[i];


	int mxau = mp[au[0]];
	int mxsu = mp[su[0]];
	int ans = 0;
	for(int i = 1 ; i < m ;i++){
		if(mp[au[i]] > mxau){
			mxau = mp[au[i]];
			mxsu = mp[su[i]];
			ans = i ;
		}
		else if(mp[au[i]] == mxau && mp[su[i]] >  mxsu){
			mxsu = mp[su[i]];
			ans = i ;
		}
	}
	cout<<ans +1<<endl;
	return 0;
}

