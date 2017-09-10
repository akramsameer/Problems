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
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int n, a, b, color[301];
vi adj[301];
bool solve(int st) {
	color[st] = 0;
	queue<int> q;
	q.push(st);
	bool ret = 1;
	while (q.size() && ret) {
		int u = q.front();
		q.pop();
		for (int i = 0; i < sz(adj[u]); i++) {
			int v = adj[u][i];
			if (color[v] == OOI) {
				color[v] = 1 - color[u];
				q.push(v);
			}
			else if(color[v] == color[u]){
				ret = false;
				break;
			}
		}
	}
	return ret;
}
int main() {
	file();
	while (cin >> n, n) {
		for (int i = 0; i < 301; i++)
			color[i] = OOI , adj[i].clear();

		while (cin >> a >> b) {
			if (!a && !b)
				break;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		bool isbib = true;
		for (int i = 1; i <= n; i++) {
			if (color[i] == OOI)
				isbib = isbib && solve(i);
		}
		cout<<((isbib)? "YES":"NO")<<endl;
	}
	return 0;
}
