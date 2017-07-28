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

int n, m;
char grid[100][100];
bool vis[100][100];
struct word {
	char c;
	int x , y;

	word(char c , int x , int y) : c(c) , x(x), y(y) {}

	bool operator <(const word & e) const {
		if(x > e.x)
			return false;
		else if (x == e.x)
				return y < e.y;
		else
			return true;
	}
};

vector<word> arr;
int solve(int i, int j) {
	int ret = 0;
	for (int k = 0; k < m; ++k) {
		if (k == j)
			continue;
		if (grid[i][j] == grid[i][k]){
			vis[i][k] = 1;
			ret++;
		}
	}
	for (int k = 0; k < n; ++k) {
		if (k == i)
			continue;
		if (grid[i][j] == grid[k][j]){
			vis[k][j] = 1;
			ret++;
		}
	}
	return ret;
}

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> grid[i][j];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (vis[i][j])
				continue;
			vis[i][j] = 1;
			int fre = solve(i, j);

			if(fre)
				continue;
			arr.push_back(word(grid[i][j] , i , j));
		}
	}

	sort(arr.begin(), arr.end());

	for (int i = 0; i < arr.size(); ++i) {
		cout<<arr[i].c;
	}
	cout << endl;
	return 0;
}

