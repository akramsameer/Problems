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
int arr[1000000+9];
queue<int> qu[1000+9];
int main() {
	file();
	int t ;
	int cas = 1;
	while(cin >> t , t){
		for(int i = 0 ; i < t ; i++){
			while(!qu[i].empty())
				qu[i].pop();

			int x ;
			cin >> x ;
			for(int j = 0 ; j < x ; j++)
			{
				int y ;
				cin>> y;
				arr[y] = i;
			}
		}
		string temp;
		queue<int> combined ;
		printf("Scenario #%d\n" , cas++);
		while(cin >> temp && temp[0] != 'S'){
			if(temp[0] == 'E'){
				int x ;
				cin >> x;
				int num = arr[x];
				if(qu[num].empty())
					combined.push(num);
				qu[num].push(x);
			}
			else
			{
				int num = combined.front();
				cout<< qu[num].front()<<endl;
				qu[num].pop();
				if(qu[num].empty())
					combined.pop();
			}
		}
		printf("\n");
	}
	return 0;
}

