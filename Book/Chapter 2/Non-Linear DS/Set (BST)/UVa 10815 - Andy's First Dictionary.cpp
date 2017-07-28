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

set<string> st;
void solve(string& str) {
	string temp = "";
	for (int i = 0; i < sz(str); i++) {
		char c = tolower(str[i]);
		if(isalpha(c))
			temp.push_back(c);
		else{
			if(sz(temp)){
				st.insert(temp);
				temp ="";
			}
		}
	}
	if (temp != "")
		st.insert(temp);

}
int main() {
	file();
	string temp;

	while (cin >> temp)
		solve(temp);


	for (set<string>::iterator it = st.begin(); it != st.end(); it++)
		cout << *it << endl;

	return 0;
}

