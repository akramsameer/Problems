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
	//freopen("out.txt", "w", stdout);
#endif
}
struct dragon{
	int x , y;
	bool operator < (const dragon & e)const{
		if(x == e.x)
			return y > e.y;
		return x < e.x;
	}
}arr[1000+9];
int s  , n ;
int main() {
	file();
	cin >> s >> n;
	for(int i = 0 ; i < n ; i++)
		cin >> arr[i].x >> arr[i].y;
	sort(arr , arr + n);
	bool yes = 1;
	for(int i = 0 ; i < n ; i++){
		if(s <= arr[i].x){
			yes = 0 ;
			break;
		}
		else
			s += arr[i].y;
	}
	if(yes)
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
