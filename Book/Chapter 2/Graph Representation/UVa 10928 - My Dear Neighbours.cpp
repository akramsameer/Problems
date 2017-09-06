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
int n , p , x , arr[1000+9];

int main() {
	file();
	stringstream ss;
	cin >> n;
	while(n--){
		int mn = OOI;
		clr(arr , 0);
		cin >>  p;
		cin.ignore();
		for(int i = 0 ; i < p ; i++){
			string temp ;
			getline(cin , temp);
			ss.clear();
			ss << temp;
			while(ss >> x)
				arr[i]++;
			mn = min(arr[i] , mn);
		}
		vi ans;
		for(int i = 0 ; i < p ; i++)
			if(arr[i] == mn)
				ans.push_back(i +1);
		printf("%d" , ans[0]);
		for(int i = 1 ; i < sz(ans); i++)
			printf(" %d" , ans[i]);
		printf("\n");
	}

	return 0;
}
