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
int n , m ;
int arr[101];
int main() {
	file();
	cin >> n >> m;
	queue<int> q;
	for(int i = 0 ; i < n ; i++){
		cin>> arr[i];
		q.push(i);
	}
	int lst = -1;
	while(sz(q)){
		int ind = q.front();
		q.pop();
		arr[ind] = arr[ind] - m ;
		if(arr[ind] > 0)
			q.push(ind);
		lst = ind;
	}
	cout<<lst +1<<endl;


	return 0;
}

