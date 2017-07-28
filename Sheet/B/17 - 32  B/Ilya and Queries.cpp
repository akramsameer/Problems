#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
int n , arr[100001];
string s;

int main() {
	freopen("in.txt", "r", stdin);
	cin >> s ;
	cin>> n ;

	for(int i = 1 ; i < s.size() ; i++){
		if(s[i] == s[i-1])
			arr[i] = arr[i-1]+1;
		else
			arr[i] = arr[i-1];
	}



	for (int i = 0; i < n; ++i) {
		int l , r ;
		cin >> l >> r;
		cout<<arr[r-1] - arr[l-1]<<endl;
	}


	return 0;
}
