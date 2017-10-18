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
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
int m , c , price[25][25];
int mem[210][25];

int shop(int money , int g){
	if(money < 0)return -OOI;
	if(g == c) return m - money;
	int& ans = mem[money][g];
	if(ans != -1) return ans;
	for(int i = 1 ; i <= price[g][0] ; i++)
		ans = max(ans , shop(money - price[g][i] , g + 1));
	return ans;
}

int main() {
	file();
	int i , j , tc , score ;
	scanf("%d" , &tc);
	while(tc--){
		scanf("%d %d" , &m , &c);
		for(i = 0 ;i < c ; i++){
			scanf("%d" , &price[i][0]);
			for(j = 1 ; j <= price[i][0] ; j++)
				scanf("%d" , &price[i][j]);
		}
		clr(mem , -1);
		score = shop(m , 0);
		if(score < 0)printf("no solution\n");
		else		printf("%d\n" , score);
	}
	return 0;
}
