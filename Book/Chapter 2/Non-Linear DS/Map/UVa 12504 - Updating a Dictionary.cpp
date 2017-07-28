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
	//freopen("out.txt", "w", stdout);
#endif
}
void read(string& str, map<string, string>& mp) {
	string key = "", val = "";
	bool v = false;
	for (int i = 1; i < sz(str); i++) {
		if (str[i] == '}' && v ) {
			mp[key] = val;
			break;
		}
		if (str[i] == ',') {
			mp[key] = val;
			key = val = "";
			v = 0;
		} else if (str[i] == ':') {
			v = 1;
		} else {
			if (!v)
				key.push_back(str[i]);
			else
				val.push_back(str[i]);
		}
	}
}

int main() {
	file();
	int t;
	cin >> t;
	while (t--) {
		string old, ne;
		map<string, string> mp_old;
		map<string, string> mp_new;
		cin >> old >> ne;
		read(old, mp_old);
		read(ne, mp_new);

		bool f = 1, no = 1;
		for (map<string, string>::iterator it = mp_new.begin();
				it != mp_new.end(); it++) {
			if (mp_old.find(it->first) == mp_old.end()) {
				if (f)
					cout << '+';
				else
					cout << ',';
				cout << it->first;
				f = 0;
				no = 0;
			}
		}
		if (!f)
			printf("\n");
		f = 1;
		for (map<string, string>::iterator it = mp_old.begin();
				it != mp_old.end(); it++) {
			if (mp_new.find(it->first) == mp_new.end()) {
				if (f)
					cout << '-';
				else
					cout << ',';
				cout << it->first;
				f = 0;
				no = 0;
			}
		}
		if (!f)
			printf("\n");
		f = 1;
		for (map<string, string>::iterator it = mp_old.begin();
				it != mp_old.end(); it++) {
			if (mp_new.find(it->first) != mp_new.end()) {
				if (it->second != mp_new[it->first]) {
					if (f)
						cout << '*';
					else
						cout << ',';
					cout << it->first;
					f = 0;
					no = 0;
				}
			}
		}
		if (!f)
			printf("\n");

		if (no)
			cout << "No changes\n";
		printf("\n");
	}
	return 0;
}

