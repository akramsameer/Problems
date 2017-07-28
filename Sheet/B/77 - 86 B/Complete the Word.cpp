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

int main() {
	file();
	string str;
	cin >> str;
	int arr[26];
	int cur = 0, cnt = 0, stind = 0;
	clr(arr, -1);
	while (cur < str.size() && cnt < 26) {
		if (str[cur] != '?') {
			int ind = str[cur] - 'A';
			if (arr[ind] == -1) {
				arr[ind] = cur;
				cnt++;
				cur++;
			} else {
				cur = arr[ind] + 1;
				stind = cur;
				cnt = 0;
				clr(arr, -1);
			}
		} else {
			cur++;
			cnt++;
		}
	}

	if (cnt == 26) {
		for (int i = 0; i < sz(str); i++) {
			if (i >= stind && i < stind + 26) {
				if (str[i] == '?') {
					for (int j = 0; j < 26; j++) {
						if (arr[j] == -1) {
							char c = j + 'A';
							arr[j] = 55;
							cout << c ;
							break;
						}
					}
				}
				else
					cout<< str[i];
			}
			else{
				if(str[i] == '?'){
					cout<<"S";
				}
				else
					cout<<str[i];
			}
		}
	}
	else
		cout <<"-1";

	cout<<endl;

	return 0;
}

