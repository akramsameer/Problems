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
int n, arr[101], mem[101][4];

int solve(int ind, int par) {
	if (ind >= n)
		return 0;

	int& ret = mem[ind][par];
	if(ret != -1)
		return ret;

	if (arr[ind] == 0)
		return ret = solve(ind + 1, arr[ind]) + 1;
	else if(arr[ind] == 1){
		if(par!= 1)
			ret = solve(ind+1 , 1);
		else
			ret = solve(ind+1 , 0) +1;
	}
	else if(arr[ind] == 2){
		if(par != 2)
			ret = solve(ind+1 , 2);
		else
			ret = solve(ind+1 , 0) +1;
	}
	else if(arr[ind] == 3){
		if(par == 0)
			ret = min(solve(ind+1 , 1) , solve(ind+1 , 2));
		else if(par == 1)
			ret = solve(ind+1 , 2);
		else if(par == 2)
			ret = solve(ind+1 ,1);
	}

	return ret;
}

int main() {
	file();
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	clr(mem , -1);
	int ans = solve(0, 0);
	cout<<ans<<endl;
	return 0;
}

