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
map<int, int> mp;
int n, x , arr[100000 +9] , arr2[100000+9];

int main() {
	file();
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mp[arr[i]]++;
	}

	for (int i = 0; i < n - 1; i++){
		cin >> arr2[i];
		mp[arr2[i]]--;
	}
	for(map<int , int> :: iterator it = mp.begin() ; it != mp.end() ; it++)
		if(it-> second){
			cout<<it->first<<endl;
			it-> second--;
		}

	for(int i = 0 ; i < n -1 ; i++)
		mp[arr2[i]]++;

	for(int i = 0 ; i < n -2 ;i++){
		cin >> x;
		mp[x]--;
	}

	for(int i = 0 ; i < n-1 ; i++)
		if(mp[arr2[i]]){
			cout<<arr2[i]<<endl;
			mp[arr2[i]]--;
		}

	return 0;
}
