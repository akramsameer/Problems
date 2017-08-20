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
int xdir[] = { -1, 0, 0, 1 };
int ydir[] = { 0, -1, 1, 0 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
struct job {
	int id, d, f;

	bool operator <(const job & b) const {
		if (d * b.f != b.d * f)
			return d * b.f < b.d * f;
		else
			return id < b.id;
	}
};
int  t , n ;
job arr[1000+5];
int main() {
	file();
	cin >> t ;
	while(t--){
		cin >> n;
		for(int i = 0 ; i < n ; i++){
			cin >>arr[i].d>>arr[i].f;
			arr[i].id = i +1;
		}
		sort(arr , arr + n);
		cout<< arr[0].id;
		for(int i = 1  ; i < n ; i++)
			cout<<" "<<arr[i].id;
		printf("\n");
		if(t)
			printf("\n");
	}
	return 0;
}
