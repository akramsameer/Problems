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
#endif
}
int arr[1000+9] , t , n;
int main() {
	file();
	cin >> t;
	while (t--) {
		cin >> n;
		for(int i = 0 ; i < n ;i++)
			cin>> arr[i];

		int cnt = 0;
		for(int i = 1 ; i < n ; i++){
			for(int j = i -1; j >= 0 ; j--){
				if(arr[j] <= arr[i])
					cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
