#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
#define EPS 1e-9
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
const double PI = acos(-1.0);
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int ydir[] = { 0, 1, -1, 1, -1, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
string s;
int n, fi[26], uni = 0, B[26];
vector<char> v;

int main() {
	file();
	cin >> s >> n;
	for (int i = 0; i < sz(s); i++) {
		int ind = s[i] - 'a';
		if (!fi[ind]) {
			uni++;
			v.push_back(s[i]);
		}
		fi[ind]++;
	}
	if (n < uni) {
		printf("-1\n");
		return 0;
	}
	int ans = 1;
	while(true){
		int num = 0;
		for(int i = 0 ; i < 26 ; i++)
			num += (fi[i] + ans -1) / ans;
		if(num <= n)
			break;
		ans ++;
	}
	vector<char >v;
	for(int i = 0 ; i < 26 ; i++){
		int occ = (fi[i] + ans -1)/ans;
		while(occ--)
			v.push_back(char(i + 'a'));
	}


	cout<< ans <<endl;
	while(sz(v) < n)
		v.push_back('a');
	for(int i = 0 ; i < sz(v); i++)
		cout<<v[i];
	printf("\n");

#ifndef ONLINE_JUDGE
	cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
