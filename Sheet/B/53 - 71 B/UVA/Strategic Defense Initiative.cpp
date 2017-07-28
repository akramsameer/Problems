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
int t , n;
vi  arr;
vi vec;
int mem[1000000];
int solve(int ind , int val){
	if(ind == sz(arr))
		return 0 ;

	int ret1 = 0 , ret2 = 0 ;
	int& ret = mem[ind] ;

	if(ret != -1)
		return ret;

	if(arr[ind] > val){
		ret1 = solve(ind +1 , arr[ind]) +1 ;
		ret2 = solve(ind +1 , val);

		if(ret1 > ret2){
			vec.push_back(arr[ind]);
			ret = ret1;
		}
		else
			ret = ret2;
	}
	else
		return 0 ;

	return ret;
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> t;
	getchar();
			getchar();
	while (t--) {

		char temp[100];
		n = 0;
		clr(mem , -1);
		vec.clear();
		while (gets(temp)) {
			if(temp[0]=='\0')break;
			int c ;
			sscanf(temp , "%d" , &c);
			arr.push_back(c);
		}

		int res = solve(0 , -1);
		cout<<"Max hits: "<<res<<endl;
		for(int i = sz(vec) -1 ; i >= 0; i--)
			cout<<vec[i]<<endl;
		if(t)
		cout<<endl;

	}

	return 0;
}
