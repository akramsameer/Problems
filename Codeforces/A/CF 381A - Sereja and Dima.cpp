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
int n , arr[1000 +9] , ser , di;
int main() {
	file();
	cin >> n;
	for(int i = 0 ; i < n ;i++)
		cin >> arr[i];
	int st = 0 , en = n-1;
	bool f = 1;
	while(st <= en){
		if(arr[st] > arr[en]){
			if(f)
				ser += arr[st++];
			else
				di += arr[st++];
			f = !f;
		}
		else
		{
			if(f)
				ser += arr[en--];
			else
				di += arr[en--];
			f = !f;
		}
	}
	cout<< ser <<' '<<di<<endl;

	return 0;
}
