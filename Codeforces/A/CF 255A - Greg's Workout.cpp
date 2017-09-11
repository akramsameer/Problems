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
int n  , x;
int arr[4];
int main() {
	file();
	cin >> n ;
	for(int i = 0 , k = 1 ; i < n ; i++ , k++){
		cin >> x;
		if(k == 4)
			k = 1;
		arr[k] += x;
	}
	int mx = max_element(arr , arr + 4) -arr;
	if(mx == 1)
		printf("chest\n");
	else if (mx == 2)
		printf("biceps\n");
	else
		printf("back\n");
	return 0;
}

