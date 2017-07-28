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
int t   , n;
bool arr[3][3];

int main() {
	freopen("in.txt", "r", stdin);
	cin >> t ;
	while(t--){
		cin >> n ;
		bool weak = true;
		int curx=-1, cury=-1;
		for(int i = 0 ; i < n ; i ++){
			int x , y ;
			cin >> x >> y ;
			if(curx == -1){
				curx = x;
				cury = y;
				continue;
			}
			if(x != curx && y != cury)
			{
				weak = false;
				break;
			}
			curx = x;
			cury = y;
		}


		if(weak)
			cout<<"weak"<<endl;
		else
			cout<<"strong"<<endl;
	}
	return 0;
}
