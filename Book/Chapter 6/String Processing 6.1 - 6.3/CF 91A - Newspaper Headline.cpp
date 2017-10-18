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
const double PI = acos(-1.0);
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int ydir[] = { 0, 1, -1, 1, -1, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int b[26], nex[26][100 + 9];
string s1, s2;

void process(string str) {
	int n = sz(str);

	for (int i = 0; i < 26; i++)
		nex[i][n] = -1;

	for (int i = n - 1; i >= 0; i--) {

		for (int j = 0; j < 26; j++)
			nex[j][i] = nex[j][i + 1];

		nex[str[i] - 'a'][i] = i;
	}

	for (int i = n; i >= 0; i--) {
		for (int j = 0; j < 26; j++)
			if (nex[j][i] == -1)
				nex[j][i] = nex[j][(i + 1) % (n + 1)];
	}
}
int main() {
	file();
	cin >> s1 >> s2;

	process(s1);
	int ans  = 0  , idx = sz(s1);

	for (int i = 0; i < sz(s2); i++) {
		int ch = s2[i] - 'a';
		int nxtId = nex[ch][idx];
		if(nxtId == -1){
			ans = -1 ;
			break;
		}
		if(nxtId < idx)
			++ans;
		idx = nxtId +1;
	}
	cout<<ans<<endl;
	return 0;
}
