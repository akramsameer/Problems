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
const int A = 0;
const int B = 1;
const int C = 2;
int arr[3];
string str;
void print(int ind) {
	if (ind == A)
		cout << "A";
	else if (ind == B)
		cout << "B";
	else
		cout << "C";
}
int main() {

	freopen("in.txt", "r", stdin);

	int cnt = 3;
	while (cnt) {
		cin >> str;
		char c = str[0];
		char op = str[1];
		char c2 = str[2];

		if (op == '>') {
			if (c == 'A')
				arr[A]++;
			else if (c == 'B')
				arr[B]++;
			else if (c == 'C')
				arr[C]++;
		} else if (op == '<') {
			if (c2 == 'A')
				arr[A]++;
			else if (c2 == 'B')
				arr[B]++;
			else if (c2 == 'C')
				arr[C]++;
		}

		cnt--;
	}
	bool vis[] = { 0 ,0 , 0};
	int minInd = 0;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (arr[minInd] > arr[j] && !vis[j])
				minInd = j;
		}
		print(minInd);
		vis[minInd] = 1;
		int t = 3 , ind = 0;
		while(t--){
			if(!vis[ind]){
				minInd = ind;
				break;
			}
			ind++;
		}
	}
	cout << endl;

	return 0;
}

