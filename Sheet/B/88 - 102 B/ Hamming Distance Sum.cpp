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
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}

int main() {
	file();
	int n ,fsum = 0 , ssum = 0;
	vi f , s;
	cin >> n ;
	int x;
	while(n--){

		cin >> x ;
		if(x > 0){
			fsum += x;
			f.push_back(x);
		}
		else{
			ssum += -x;
			s.push_back(-x);
		}
	}
	if(fsum > ssum)
		cout<<"first"<<endl;
	else if( ssum > fsum)
		cout<<"second"<<endl;
	else{
		for(int i = 0 ; i < sz(f) ; i++){
			if(f[i] > s[i]){
				cout<<"first"<<endl;
				return 0;
			}
			else if(s[i]>f[i]){
				cout<<"second"<<endl;
				return 0;
			}
		}
		if(x > 0)
			cout<<"first"<<endl;
		else
			cout<<"second"<<endl;
	}
	return 0;
}

