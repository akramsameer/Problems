#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
int values[20001], t , n , parent[20001];
void print(int cur){
	stack<int> s ;
	while(parent[cur]){
		s.push(values[cur]);
		cur = parent[cur];
	}
	s.push(1);
	while(!s.empty()){
		printf("%d" , s.top());
		s.pop();
	}
	printf("\n");
	return ;
}
void solve(){
	queue<int> q;
	q.push(1);
	parent[1] = 0 ;
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if(cur == 0){
			print(cur);
			return ;
		}
		int temp = (cur * 10)% n ;
		if(parent[temp] == -1){
			q.push(temp);
			parent[temp] = cur;
			values[temp] = 0;
		}
		temp = (cur*10 +1)% n;
		if(parent[temp] == -1){
			q.push(temp);
			parent[temp] = cur ;
			values[temp] = 1;
		}
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	scanf("%d\n" , &t);
	while(t--){
		memset(parent , -1 , sizeof parent);
		scanf("%d\n" , &n);
		solve();
	}
	return 0;
}
