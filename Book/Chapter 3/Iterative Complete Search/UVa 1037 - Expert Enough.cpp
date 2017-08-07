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
#endif
}
int t ,ind, d , q , p , l[10000+9] , hi[10000+9] ;
string names[10000+9];
int main() {
	file();
	cin >> t;
	while(t--){
		cin >> d ;
		for(int i = 0 ; i  < d ; i++)
			cin >> names[i] >> l[i] >> hi[i];
		cin >> q;

		while(q--){
			ind = -1;
			cin >> p;
			for(int i = 0 ; i < d ; i++){
				if(p >= l[i] && p <= hi[i]){
					if(ind == -1)
						ind = i;
					else{
						ind = -1 ;
						break;
					}
				}
			}
			if(ind != -1)
				cout<<names[ind]<<endl;
			else
				cout<<"UNDETERMINED"<<endl;
		}
		cout<<endl;
	}
	return 0;
}
