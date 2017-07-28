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
int arr[100];
int main() {
	file();
	int n ;
	int t = 1;

	while(cin >> n , n){
		int sum = 0 ;
		for(int i = 0 ; i < n ; i ++)
			cin >> arr[i] , sum += arr[i];

		int k = sum / n ;
		int diff = 0;
		for(int i = 0 ; i < n ; i++)
			diff += abs(k  - arr[i]);

		printf("Set #%d\n" , t++);
		printf("The minimum number of moves is %d.\n\n" , diff/2);

	}
	return 0;
}

