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
int t;
string s;
struct node {
	char c;
	int f;

	bool operator <(const node & e) const {
		if(f == e.f)
			return c < e.c;
		else
			return f < e.f;
	}
};
int main() {
	freopen("in.txt", "r", stdin);
	cin>> t;
	while (t--) {
		cin >> s;
		node arr[26];
		for (int i = 0; i < 26; ++i){
			arr[i].f = 0;
			arr[i].c = 'a' + i;
		}

		for (int i = 0; i < s.size(); ++i) {
			int ind = s[i] - 'a';
			arr[ind].f++;
		}
		sort(arr , arr+26);
		int st=-1 , end=-1;
		for (int i = 0; i < 26; ++i) {
			if(st == -1 && arr[i].f != 0){
				st = i;
			}

			if(arr[i].f != 0)
				end = i;
		}
		int n = end -st +1;
		if(n & 1){
			int ind = ceil((double)n/2);
			cout<< arr[st+ind-1].c<<endl;
		}
		else
		{
			int ind = st + n / 2 -1;

			cout<< arr[ind].c<<arr[ind+1].c<<endl;
		}
	}

	return 0;
}
