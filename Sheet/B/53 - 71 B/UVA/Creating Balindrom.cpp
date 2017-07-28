#include<bits/stdc++.h>

#define REP(i,s,n) for(int i=s;i<n;i++)
#define rep(i,n) REP(i,0,n)

using namespace std;

int N,K;
int v[10010];

int dfs(int L,int R,int k){
  if( k > K ) return K+1;
  if( L >= R ) return k;
  if( v[L] == v[R-1] ) return dfs(L+1,R-1,k);
  return min(dfs(L+1,R,k+1),dfs(L,R-1,k+1));
}

int main(){
  int T,CNT=1;
  cin >> T;
  while( T-- ){
    printf("Case %d: ",CNT++);
    cin >> N >> K;
    rep(i,N) cin >> v[i];
    int res = dfs(0,N,0);
    if( res == 0 )     puts("Too easy");
    else if( res > K ) puts("Too difficult");
    else               printf("%d\n",res);
  }
  return 0;
}
