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
int t, a, b, c;
queue<ii> q;
bool vis[2][2][40001];
int cost[2][2][40001];
void clear() {
	while (q.size())
		q.pop();
	memset(vis , 0 , sizeof vis);
}
void values(int cura, int curb, int& x, int& y, int&z) {
	if (!cura)
		x = 0, y = 1, z = curb;
	else if (cura == a)
		x = 0, y = 0, z = curb;
	else if (!curb)
		x = 1, y = 1, z = cura;
	else
		x = 1, y = 0, z = cura;

}
void pu(int x, int y , int co) {
	int xx , yy , zz;
	values(x , y , xx , yy , zz);
	if (!vis[xx][yy][zz]) {
		q.push(make_pair(x, y));
		vis[xx][yy][zz] = 1;
		cost[xx][yy][zz] = co;
	}
}
void get(int & cura, int & curb) {
	if (cura + curb > b) {
		cura = cura - (b - curb);
		curb = b;
	} else {
		curb += cura;
		cura = 0;
	}
}
void geta(int &cura, int & curb) {
	if (cura + curb > a) {
		curb = curb - (a - cura);
		cura = a;
	} else {
		cura += curb;
		curb = 0;
	}
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> t;
	while (--t) {
		cin >> a >> b >> c;
		clear();

		q.push(make_pair(0, 0));
		vis[0][1][0] = 1;
		while (q.size()) {
			ii cur = q.front();
			q.pop();
			int cura = cur.first, curb = cur.second;
			int x , y , z;
			values (cur.first , cur.second , x , y , z);
			if(cura == c || curb == c){
				cout<< cost[x][y][z] << endl;
				break ;
			}
			int co = cost[x][y][z] +1;
			get(cura, curb);
			pu(cura, curb , co);		//  a ==> b
			geta(cura, curb);
			pu(cura, curb , co);		//  b ==> a
			pu(0, curb , co);			//  a ==> 0
			pu(cura, 0 , co);			//  b ==> 0
			pu(a, curb , co);			//  fill a
			pu(cura , b , co);			//  fill b
		}
		cout<<"-1"<<endl;
	}
	return 0;
}
