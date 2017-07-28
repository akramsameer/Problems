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

const int ALLIN = 0;
const int IN = 1;
const int FOLDED = 2;

int n, arr[3];
char* s;
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n;
	s = new char[n];
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		if (s[i] == 'A')
			arr[ALLIN]++;
		else if (s[i] == 'I')
			arr[IN]++;
		else
			arr[FOLDED]++;
	}
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (s[i] != 'F') {
			if (s[i] == 'A')
				arr[ALLIN]--;
			else if (s[i] == 'I')
				arr[IN]--;

			if (arr[IN] == 0)
				cnt++;
			if (s[i] == 'A')
				arr[ALLIN]++;
			else if (s[i] == 'I')
				arr[IN]++;

		}
	}
	cout<<cnt<<endl;
	return 0;
}

