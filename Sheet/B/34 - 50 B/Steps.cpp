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
int n , m ;
set<int> S;
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m ;
	bool f = false;
	for(int i = 0 ; i < n; i++){
		int g , s;
		for(int j = 0 ; j < m ; j++){
			char c  ;
			cin >> c ;
			if ( c == 'G')
				g = j + 1 ;
			else if(c == 'S')
				s = j +1;
		}

		if(s - g < 0){
			f = 1;
			break;
		}
		else
			S.insert(s-g);
	}

	if(f)
		cout<<"-1"<<endl;
	else
		cout<<S.size()<<endl;
	return 0;
}
