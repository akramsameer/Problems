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
string s;

int main() {
	freopen("in.txt", "r", stdin);
	cin >> s;
	int cx = 0, cy = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'x')
			cx++;
		else
			cy++;
	}
	if(cx>cy){
		for(int i = 0 ; i < cx-cy;i++)
			cout<<'x';
	}else
		for(int i = 0 ; i < cy - cx ; i++)
			cout << 'y' ;
	cout<<endl;
	return 0;
}
