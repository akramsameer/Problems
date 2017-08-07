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
int calc(int arr[] , int i , int j , int n){
	int ret = 0;
	for(int k = 0 ; k < n ; k++){
		if(k >= i && k <= j)
			ret += (arr[k] == 0)?1:0;
		else
			ret += (arr[k] == 1)?1:0;
	}
	return ret;
}
int main() {
	file();
	int n , mx = 0, arr[100 + 9];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for(int i = 0 ; i < n ;i++){
		for(int j = i ; j < n ; j++){
			mx =max(mx , calc(arr , i , j , n));
		}
	}

		cout <<  mx << endl;
	return 0;
}
