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
int xdir[] = { 1, 1, 1, -1, -1, -1, 0, 0 };
int ydir[] = { 0, 1, -1, 1, -1, 0, -1, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
}
struct point{
	double x , y ;
	point(){x = y = 0.0;}
	point(double _x , double _y):x(_x) , y(_y){}
};
ll ax , ay , bx , by , tx , ty ;
double ans ;
int n;
vector<pair<double ,int> > v1 , v2;
int main() {
	file();
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	cin >> n;
	for(int i = 0 ; i < n ;i++){
		ll xi , yi ;
		cin >> xi >> yi;
		ans += 2 * hypot(double(xi - tx),double( yi - ty));
		v1.push_back(make_pair(hypot(double(xi - ax) ,double( yi - ay)) - hypot(double(xi - tx) ,double( yi - ty))  , i));
		v2.push_back(make_pair(hypot(double(xi - bx) ,double( yi - by)) - hypot(double(xi - tx) ,double( yi - ty))  , i));
	}
	sort(v1.begin() , v1.end());
	sort(v2.begin() , v2.end());

	if(v1[0].second == v2[0].second){
		ans += min(v1[1].first + v2[0].first ,v1[0].first + v2[1].first);
	}else
		ans = min( min(ans + v1[0].first , ans+v2[0].first ),ans+ v1[0].first + v2[0].first);

	cout<<fixed<<setprecision(12)<<ans<<endl;
	return 0;
}

