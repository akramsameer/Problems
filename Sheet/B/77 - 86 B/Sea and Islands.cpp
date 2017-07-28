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
	int n , k;
	cin >> n >> k ;
	vector< string > ans (n , "");
	for(int i = 0 ; i < n ;i++){
		for(int j = 0 ; j < n ; j++){
			if((i + j )% 2 == 0 && k >0){
				k--;
				ans[i]+='L';
			}
			else
				ans[i]+='S';
		}
	}

	if(k == 0){
		cout<<"YES"<<endl;
		for(int i = 0 ; i < n ;i++)
			cout<<ans[i]<<endl;
	}else
		cout<<"NO"<<endl;
	return 0;
}

