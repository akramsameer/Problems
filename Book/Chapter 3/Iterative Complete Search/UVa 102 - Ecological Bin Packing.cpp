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
const int B = 0, G = 2, C = 1;
int arr[3][3];
int calc(int A[]) {
	int ret = 0;
	for (int i = 0; i < 3; i++) {
		if (A[i] == B)
			for (int j = 0; j < 3; j++) {
				if (i == j)
					continue;
				ret += arr[j][0];
			}
		else if (A[i] == G) {
			for (int j = 0; j < 3; j++) {
				if (i == j)
					continue;
				ret += arr[j][2];
			}
		} else
			for (int j = 0; j < 3; j++) {
				if (i == j)
					continue;
				ret += arr[j][1];
			}
	}
	return ret;
}
string print(int A[]) {
	string ret = "";
	for (int i = 0; i < 3; i++) {
		if (A[i] == B)
			ret += 'B';
		else if (A[i] == G)
			ret += 'G';
		else
			ret += 'C';
	}
	return ret;
}
int main() {
	file();
	int x;
	while (cin >> arr[0][0]) {
		cin >> arr[0][2] >> arr[0][1];
		for (int i = 1; i < 3; i++)
			cin >> arr[i][0] >> arr[i][2] >> arr[i][1];

		int mx = OOI;
		string ans = "";
		for (int a = 0; a < 3; a++) // B
			for (int b = 0; b < 3; b++) // clear
				for (int c = 0; c < 3; c++) { //Green
					if (a != b && b != c && a != c) {
						int A[] = { a, b, c };
						int mov = calc(A);
						if (mov < mx) {
							mx = mov;
							ans = print(A);
						}

					}
				}
		cout << ans << " " << mx << endl;
	}
	return 0;
}
