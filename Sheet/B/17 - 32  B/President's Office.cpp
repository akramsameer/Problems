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
char arr[101][101];
int n, m, cnt = 0;
bool c[27];
char ch;
bool valid(int x , int y){
	if(x < n && x >= 0 && y < m && y >= 0)
		return true;
	return false;
}

void check(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + xdir[i];
		int ny = y + ydir[i];
		if(!valid(nx , ny))
			continue;
		char  temp = arr[nx][ny];
		if (temp != '.' && temp != ch) {
			int ind = temp - 'A';
			if (!c[ind]) {
				c[ind] = 1;
				cnt++;
			}

		}
	}
}
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m >> ch;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == ch)
				check(i, j);
		}
	cout << cnt << endl;
	return 0;
}
