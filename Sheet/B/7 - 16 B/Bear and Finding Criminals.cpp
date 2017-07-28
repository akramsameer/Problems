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

const int ALLIN = 0;
const int IN = 1;
const int FOLDED = 2;
// TODO (1) save it before you delete it
int n , ind ;
bool arr[101];
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n >> ind;
	for(int i = 0 ; i < n ; i++)
		cin>> arr[i];

	int dis = 0  , cnt = 0;
	ind--;
	while(ind + dis < n || ind-dis >= 0){

		if(ind + dis < n && ind-dis >= 0){
			if(arr[ind+dis] && arr[ind-dis]){
				cnt++;
				if(ind+ dis != ind-dis)
					cnt++;
			}
		}
		else if(ind + dis < n && arr[ind+dis])
			cnt++;
		else if(ind-dis >= 0 && arr[ind-dis])
			cnt++;
		dis++;
	}
	cout << cnt<<endl;
	return 0;
}

