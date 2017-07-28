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
char v[] = { '(', ')', '[', ']' };
int t;
string s;
bool balanced(string str) {
	stack<char> st;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(' || str[i] == '[')
			st.push(str[i]);
		else if (str[i] == ']' && (st.empty() || st.top() != '['))
			st.push(str[i]);
		else if (str[i] == ')' && (st.empty() || st.top() != '('))
			st.push(str[i]);
		else
			st.pop();
	}
	return st.size() == 0;
}

int solve() {
	map<string, bool> mp;
	queue<pair<string, int> > q;

	q.push(make_pair(s, 0));
	while (q.size()) {
		string str = q.front().first;
		int cos = q.front().second;
		q.pop();
		mp[str] = 1;

		if (balanced(str))
			return cos;

		for (int i = 0; i < str.length(); i++) {
			string o = str;

			for (int j = 0; j < 4; j++) {

				if (o[i] == v[j])
					continue;
				char temp = o[i];
				o[i] = v[j];
				if (!mp[o])
					q.push(make_pair(o, cos + 1));

				o[i] = temp;
			}

		}

	}
	return -1;
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> t;
	while (t--) {
		cin >> s;
		bool f = balanced("[]])");
		int cost = solve();
		cout << cost << endl;
	}
	return 0;
}
