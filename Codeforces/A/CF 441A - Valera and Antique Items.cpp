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
int n  , v , k , s;
int main() {
	file();
	cin >> n >> v;
	vi ans;
	for(int i = 0 ; i < n ; i++){
		cin >> k ;
		bool flag = 0 ;
		for(int j = 0 ; j < k ; j++){
			cin >> s ;
			if(v > s)
				flag = 1;
		}
		if(flag)
			ans.push_back(i+1);
	}
	cout<< sz(ans)<<endl;
	for(int i = 0 ; i < sz(ans) ; i++)
		cout<< ans[i]<<" ";
	cout<<endl;
	return 0;
}
