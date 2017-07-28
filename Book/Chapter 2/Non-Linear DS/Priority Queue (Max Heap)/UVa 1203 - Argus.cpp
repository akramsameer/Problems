#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
#define clr(v , d)	memset(v , d , sizeof v)
#define sz(v)		((int)(v).size())
#define isPowerOfTwo(S) (!(S & (S - 1)))
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
#define f first
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
struct query {
	int id , cur , per;
	query(int id , int cur , int per):id(id) , cur(cur ) , per(per){};

	bool operator < (const query& e)const{
		if(cur > e.cur)
			return 1;
		else if (cur == e.cur && id > e.id)
			return 1 ;
		return 0;
	}
};

int main() {
	file();
	string temp ;
	priority_queue<query> q;
	while(cin >> temp){
		if(temp[0] == '#')
			break;

		int id , per ;
		cin >> id >> per;
		q.push(query(id , per , per));
	}
	int k ;
	cin >> k ;
	while(k--){
		int id = q.top().id;
		int cur = q.top().cur;
		int per = q.top().per;
		q.pop();
		printf("%d\n" , id);
		q.push(query(id , cur + per , per));
	}
	return 0;
}

