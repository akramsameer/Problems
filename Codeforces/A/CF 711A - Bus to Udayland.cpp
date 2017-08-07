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
#endif
}

int main() {
	file();
	char arr[1000 + 9][5];
	int n;
	cin  >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];

	bool yes = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i][0] == 'O' && arr[i][1] == 'O') {
			arr[i][0] = arr[i][1] = '+';
			yes = 1;
			break;
		}
		if (arr[i][3] == arr[i][4] && arr[i][3] == 'O') {
			arr[i][3] = arr[i][4] = '+';
			yes = 1;
			break;
		}
	}
	if (yes) {
		printf("YES\n");
		for (int i = 0; i < n; i++) {
			for(int j = 0 ; j < 5 ; j++)
				cout<<arr[i][j];
			cout<<endl;
		}
	}
	else
		printf("NO");
	return 0;
}
