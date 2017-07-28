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
bool theive[100005] , vis[100005];
int t;
queue<ii> q;
void getnext(int cur, int dep) {
	char src[4];
	for (int i = 0; i < 4; ++i) {
		src[3 - i] = cur % 10;
		cur /= 10;
	}

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 4; ++j) {
			int k = src[j];
			src[j] = i;
			int newcur = 0;
			for (int o = 0; o < 4; ++o)
				newcur = newcur * 10 + src[o];

			if(theive[newcur] && !vis[newcur] && newcur > 1000){
				q.push(ii(newcur , dep));
				vis[newcur] = 1;
			}
			src[j] = k;
		}
	}

}

int bfs(int s, int e) {
	while (q.size())
		q.pop();
	memset(vis , 0 , sizeof vis);
	q.push(ii(s, 0));
	vis[s] = 1;
	while (q.size()) {
		int cur = q.front().first;
		int dep = q.front().second;
		q.pop();
		if (cur == e)
			return dep;

		getnext(cur, dep+1);
	}
	return -1;
}

int main() {
	freopen("in.txt", "r", stdin);
	theive[1] = theive[0] = 0;

	for (int i = 2; i < 100000; ++i)
		theive[i] = true;

	for (int var = 2; var < 100000; ++var)
		if (theive[var])
			for (int i = var + var; i < 100000; i += var)
				theive[i] = false;

	scanf("%d\n", &t);
	while (t--) {
		int s, e;
		scanf("%d%d\n", &s, &e);
		int ans =bfs(s, e);
		if(ans != -1)
			printf("%d\n" , ans);
		else
			printf("Impossible\n");
	}
	return 0;
}
