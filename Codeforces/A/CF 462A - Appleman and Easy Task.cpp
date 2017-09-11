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
char arr[101][101];
int n;
int main() {
	file();
	cin >> n ;
	for(int i = 0 ; i < n ; i ++)
		for(int j = 0 ; j < n ; j++)
			cin >> arr[i][j];
	bool yes = 1 ;
	for(int i = 0 ;  i < n ; i++){
		for(int j = 0 ; j< n; j++){
			int num = 0;
			for(int k = 0 ; k < 4 ; k++){
				int x = i + xdir[k];
				int y = j + ydir[k];
				if(x < 0 || y < 0 || x >= n || y >= n)continue;
				if(arr[x][y] == 'o')
					num++;
			}
			if(num & 1){
				yes = 0;
				break;
			}
		}
	}
	if(yes)
		printf("YES\n");
	else
		printf("NO");
	return 0;
}

