#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
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
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
int t, n;
string arr[100000 + 9];
void mani() {

	for (int i = 0; i < n; i++) {
		string temp;
		for (int j = 0; j < sz(arr[i]); j++) {
			if (sz(temp) == 3)
				temp.push_back('-');

			char c = arr[i][j];
			if (isalpha(c)) {
				if (c == 'A' || c == 'B' || c == 'C')
					temp.push_back('2');
				else if (c == 'D' || c == 'E' || c == 'F')
					temp.push_back('3');
				else if (c == 'G' || c == 'H' || c == 'I')
					temp.push_back('4');
				else if (c == 'J' || c == 'K' || c == 'L')
					temp.push_back('5');
				else if (c == 'M' || c == 'N' || c == 'O')
					temp.push_back('6');
				else if (c == 'P' || c == 'R' || c == 'S')
					temp.push_back('7');
				else if (c == 'T' || c == 'U' || c == 'V')
					temp.push_back('8');
				else if (c == 'W' || c == 'X' || c == 'Y')
					temp.push_back('9');
			} else if (isdigit(c))
				temp.push_back(c);
		}
		arr[i] = temp;
	}
}
int main() {
	file();
	cin >> t;
	while (t--) {
		cin >> n;
		bool flag = 1;
		for (int i = 0; i < n; i++)
			cin >> arr[i];

		mani();
		sort(arr ,arr+n);

		string prev = arr[0];
		int cnt = 1 ;
		for (int i = 1; i < n; i++){
			if(arr[i] != prev){
				if(cnt > 1){
					printf("%s %d\n" , prev.c_str() , cnt);
					flag = 0;
				}prev = arr[i];
				cnt = 1;
			}
			else{
				cnt++;
			}
		}

		if(cnt > 1){
			printf("%s %d\n" , arr[n-1].c_str() , cnt);
			flag = 0;
		}
		if(flag)
			printf("No duplicates.\n");
		if(t)
			printf("\n");
	}
	return 0;
}

