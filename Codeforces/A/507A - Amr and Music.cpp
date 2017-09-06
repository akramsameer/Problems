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
int n , k , arr[100 +9] , vis[100 +9];
int main() {
	file();
	cin >> n >> k ;
	for(int i = 0 ; i < n ; i++)
		cin>> arr[i];
	bool yes = 0;
	vi ans;
	for(int i = 0 ; i < n ; i++){
		int smt = OOI;
		int ind = -1;
		for(int j = 0 ; j < n ; j++){
			if(smt > arr[j] && !vis[j])
			{
				smt = arr[j];
				ind = j +1 ;
			}
		}
		if(smt <= k){
			k -= smt;
			yes = 1;
			vis[ind -1] = 1;
			ans.push_back(ind);
		}
		else break;
	}
	if(!yes)
		printf("0\n");
	else
	{
		cout<< sz(ans)<<endl;
		cout<< ans[0];
		for(int i = 1; i< sz(ans) ; i++)
			printf(" %d" , ans[i])	;
	}
	return 0;
}
