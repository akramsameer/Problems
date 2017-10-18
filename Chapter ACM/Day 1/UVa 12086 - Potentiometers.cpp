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
	freopen("out.txt", "w", stdout);
#endif
}
const int N = 200000 + 5;
int arr[N];
int tree[4 * N];

int merge(int x , int y){return x + y;};

void build(int ind, int st, int en) {

	if (st == en) {
		tree[ind] = arr[st];
		return;
	}

	int mid = (st + en) / 2;
	int right = 2 * ind + 1;
	int left = 2 * ind;

	build(left, st, mid);
	build(right, mid + 1, en);

	tree[ind] = merge(tree[right], tree[left]);
}

int query(int ind , int st , int en , int i , int j){
	if(j < st || en < i)			// no intersect
		return 0;

	if(i <= st && en <= j)  		// begin & end in [i ... j]
		return tree[ind];

	int mid = (st + en) / 2 ;
	int left = 2 * ind ;
	int right = 2 * ind +1;

	int q1 = query(left , st , mid , i , j);
	int q2 = query(right, mid +1 , en, i , j);

	return merge(q1 , q2);
}
void update(int pos , int st , int en , int idx , int val){
	if(idx < st || idx > en)
		return ;

	if(st == en &&  idx == en){
		tree[pos] = val;
		arr[idx] = val;
		return ;
	}
	int mid = (st + en) / 2;
	int left = 2  * pos ;
	int right = 2 * pos +1 ;

	update(left , st , mid , idx , val );
	update(right , mid +1 , en , idx , val);

	tree[pos] = merge(tree[right] , tree[left]);
}
int k ;
int main() {
	file();
	int counter = 0;
	while(cin >> k , k){
		for(int i = 1 ; i <= k ; i++)
			cin >> arr[i];

		clr(tree , 0);
		string temp ;
		build(1 , 0 , k);
		if(counter)
			printf("\n");
		printf("Case %d:\n" , ++counter);
		while(cin >> temp){
			if(temp[0] == 'E')
				break;
			if(temp[0] == 'M'){
				int st , en ;
				cin >> st >> en;
				int res = query(1 , 0 , k , st , en);
				printf("%d\n" , res);
			}
			else {
				int idx , val ;
				cin >> idx >> val;
				update(1 , 0 , k , idx , val);
			}
		}

	}
	return 0;
}
