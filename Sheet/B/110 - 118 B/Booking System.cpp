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
ii arr[1000+9];
int k , n  , t[1001] , idx[1000+9] , idxta[1000+9];
bool vis[1000+9];
bool cmp(int a , int b){
	if(arr[a].s > arr[b].s)
		return 1;
	else if(arr[a].s == arr[b].s)
		if(arr[a].f < arr[b].f)
			return 1;
	return 0;
}
bool cmp2(int a , int b){
	if(t[a] < t[b])
		return 1;
	return 0;
}
int main() {
	file();
    scanf("%d\n", &n);
    for(int i = 0 ; i < n ; i++){
    	scanf("%d %d\n" , &arr[i].f , &arr[i].s);
    	idx[i] = i;
    }
    scanf("%d\n" , &k);
    for(int i = 0 ; i < k ; i++){
    	scanf("%d", &t[i]);
    	idxta[i] = i;
    }

    sort(idx , idx +n , cmp);
    sort(idxta , idxta+k , cmp2);

    int tot= 0  , num = 0;
    vii ans;
    for(int i = 0 ; i < n ; i++){

    	for(int j = 0 ; j < k ; j++){
    		if( !vis[ idxta[j] ] &&t[ idxta[j] ] >= arr[ idx[i] ].f){
    			tot += arr[idx[i]].s;
    			num++;
    			ans.push_back(make_pair(idx[i] , idxta[j]));
    			vis[idxta[j]] = 1;
    			break;
    		}
    	}

    }

    printf("%d %d\n" , num , tot);
    for(int i = 0 ; i < num ; i++)
    	printf("%d %d\n" , ans[i].f+1 , ans[i].s+1);
    return 0;
}

