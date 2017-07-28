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
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
int solve(string str) {
	int zeroes = 0, ones = 0;
	for (int i = 0; i < sz(str); i++) {
		if (str[i] == '1') {
			ones++;
			if (ones > 1)
				return -1;
		}
		else{
			if(str[i] == '0')
				zeroes++;
			else
				return -1;
		}
	}
	if(ones == 0)
		return 0;
	return zeroes;
}

int main() {
	file();
	int n;
	scanf("%d", &n);
	string str, arr;
	bool flag = 0;
	int zeros = 0;
	while (n--) {
		cin >> arr;
		if (sz(arr) == 1 && arr[0] == '0') {
			cout << 0 << endl;
			return 0;
		}
		int res = solve(arr);
		if(res == -1){
			flag = 1;
			str = arr;
		}else
			zeros += res;
	}
	if(flag)
		cout<<str;
	else
		cout<<1;
	while(zeros--)
		cout<<"0";
	cout<<endl;
	return 0;
}

