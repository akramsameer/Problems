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
int xdir[] = { 1, -1, 2, -2, 1, -1, 2, -2 };
int ydir[] = { 2, 2, 1, 1, -2, -2, -1, -1 };
string st, en;
bool valid(int x , int y){
	if(x < 9 && x >= 1 && y <9 && y>=1)
		return 1;
	return 0;
}
int solve() {
	ii s, e;
	s.first = st[0] - 'a' + 1;
	s.second = st[1] - '0';
	e.first = en[0] - 'a' + 1;
	e.second = en[1] - '0';
	queue<pair<pair<int, int>, int> > q;
	bool vis[9][9] = {0};
	q.push(make_pair(s, 0));
	while (q.size()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cos = q.front().second;
		q.pop();
		vis[x][y] = 1;
		if (x == e.first && y == e.second)
			return cos;

		for (int i = 0; i < 8; i++) {
			int nexx = x + xdir[i];
			int nexy = y + ydir[i];

			if (valid(nexx,nexy) && !vis[nexx][nexy]){
				q.push(make_pair(make_pair(nexx , nexy),cos+1));
			}
		}

	}
}
int main() {
	freopen("in.txt", "r", stdin);
	while (cin >> st >> en) {
		int res = solve();
		cout << "To get from " << st << " to " << en << " takes " << res
				<< " knight moves." << endl;
	}

	return 0;
}
