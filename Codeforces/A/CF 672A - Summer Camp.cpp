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
int xdir[] = { 1, -1, 0, 0 };
;
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int arr[2000];
int main() {
	file();
	int n , ind  = 1 , i = 1;
	while(ind < 1009){
		int x = i ;
		string temp ;
		while(x){
			temp.push_back((x%10)+'0');
			x /= 10;
		}
		for(int i = sz(temp) -1 ; i >= 0 ;i--)
			arr[ind++] = temp[i] - '0';
		i++;
	}
	cin >> n;
	cout<<arr[n]<<endl;
	return 0;
}

