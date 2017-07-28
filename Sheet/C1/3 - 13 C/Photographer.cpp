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
#define s second
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
int n , a , b  , idx[100000+9];
ll d ;
pair<ll , ll> arr[100000+9];

bool cmp(int x , int y){
	if(arr[x].f * a + arr[x].s*b < arr[y].f*a + arr[y].s*b)
		return 1;
	return 0;
}

int main() {
	file();
	cin >> n >> d;
	cin >> a >> b;

	for(int i = 0 ; i < n ; i++){
		idx[i] = i ;
		cin >> arr[i].f >> arr[i].s ;
	}
	int ans = 0 ;
	vi v;
	sort(idx , idx+n , cmp);
	for(int i = 0 ; i< n ; i++){
		ll lo = arr[idx[i]].f  * a;
		ll hi = arr[idx[i]].s * b;
		if(lo + hi <= d){
			ans ++;
			v.push_back(idx[i]+1);
			d -= lo + hi;
		}
		else
			break;
	}

	cout<< ans <<endl;
	for(int i = 0 ; i< sz(v) ; i++)
		cout<< v[i]<<" ";
	return 0;
}

