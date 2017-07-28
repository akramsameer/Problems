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

int main() {
	file();
	int n;
	while (cin >> n, n) {
		int arr[5];
		map<string, int> mp;
		for (int i = 0; i < n; i++) {
			cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
			sort(arr, arr + 5);
			string temp = "";
			char buf[20];
			sprintf(buf, "%d%d%d%d%d", arr[0], arr[1], arr[2], arr[3], arr[4]);
			temp = buf;
			mp[temp]++;
		}


		int mx = 0 , ans= 0;
		for(map<string , int>:: iterator it = mp.begin() ; it!= mp.end();it++){
			if(it->second >  mx)
				mx = it->second , ans = (*it).second;
			else if ((*it).second == mx)
				ans += mx;
		}
		printf("%d\n" , ans	);

	}
	return 0;
}

