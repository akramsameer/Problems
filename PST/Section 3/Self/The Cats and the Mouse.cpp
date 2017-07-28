#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
bool msvis[100][100], cvis[100][100];
int n, m, k, msposx, msposy, cpos1x, cpos1y, cpos2x, cpos2y, msgrid[100][100],
		cgrid[100][100];
void msclear() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			msvis[i][j] = 0;
}
void cclear() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cvis[i][j] = 0;
}
bool valid(int x, int y) {
	if (x < 0 || x >= n || y < 0 || y >= m)
		return false;
	return true;
}

void mbfs(int mx, int my) {
	queue<ii> q;
	msclear();
	mx--, my--;
	q.push(make_pair(mx, my));
	msgrid[mx][my] = 0;
	while (!q.empty()) {
		ii cur = q.front();
		q.pop();
		int nx = cur.first, ny = cur.second;
		msvis[nx][ny] = 1;
		for (int i = 0; i < 4; ++i) {
			int nex = nx + xdir[i], ney = ny + ydir[i];

			if (valid(nex, ney) && !msvis[nex][ney]
					&& msgrid[nex][ney] > msgrid[nx][ny] + 1) {
				q.push(make_pair(nex, ney));
				msgrid[nex][ney] = msgrid[nx][ny] + 1;
			}
		}
	}
}
void cbfs(int cx, int cy) {
	queue<ii> q;
	cclear();
	cx--, cy--;
	q.push(make_pair(cx, cy));
	cgrid[cx][cy] = 0;
	while (!q.empty()) {
		ii cur = q.front();
		q.pop();
		int nx = cur.first, ny = cur.second;
		cvis[nx][ny] = 1;
		for (int i = 0; i < 4; ++i) {
			int nex = nx + xdir[i], ney = ny + ydir[i];
			if (valid(nex, ney) && !cvis[nex][ney]
					&& cgrid[nex][ney] > cgrid[nx][ny] + 1) {
				q.push(make_pair(nex, ney));
				cgrid[nex][ney] = cgrid[nx][ny] + 1;
			}
		}
	}
}
bool solve() {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			msgrid[i][j] = cgrid[i][j] = 1000000;

	mbfs(msposx, msposy);
	cbfs(cpos1x , cpos1y);
	cbfs(cpos2x , cpos2y);

	for (int i = 0; i < n; ++i)
		if(msgrid[i][0] < cgrid[i][0] || msgrid[i][m-1] < cgrid[i][m-1])
			return true;

	for (int i = 0; i < m; ++i)
		if(msgrid[0][i] < cgrid[0][i] || msgrid[m-1][i] < cgrid[m-1][i])
			return true;

	return false;
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d%d\n", &n, &m);
	scanf("%d\n", &k);
	while (k--) {
		scanf("%d%d%d%d%d%d\n", &msposx, &msposy, &cpos1x, &cpos1y, &cpos2x,
				&cpos2y);
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
