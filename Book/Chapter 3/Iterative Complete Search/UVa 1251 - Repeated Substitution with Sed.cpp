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
int n;
string st, end;
pair<string, string> arr[11];
queue<pair<string, int> > q;
string man(string str, int ind) {
	string from = arr[ind].first  , to = arr[ind].second;
	int start_pos = 0;
	while((start_pos = str.find(from , start_pos)) != string::npos){
		str.replace(start_pos , from.length() , to);
		start_pos += to.length();
	}
	return str;
}

void bfs() {
	while (q.size())
		q.pop();
	q.push(make_pair(st, 0));
	map<string, bool> mp;
	mp[st] = 1;
	while (q.size()) {
		string cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == end) {
			cout << cnt << endl;
			return;
		}

		for (int i = 0; i < n; i++) {
			string ne = man(cur, i);
			if (!mp[ne] && sz(ne) < 11) {
				q.push(make_pair(ne, cnt + 1));
				mp[ne] = 1;
			}
		}
	}
	cout << "-1" << endl;
}

int main() {
	file();

	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++)
			cin >> arr[i].first >> arr[i].second;
		cin >> st >> end;
		bfs();
	}

	return 0;
}
