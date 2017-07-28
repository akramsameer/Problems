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
int n ;
int arr[100001];

int main() {
	freopen("in.txt", "r", stdin);
	cin >> n ;
	arr[0] = 0;
	for (int i = 1; i <= n ; ++i) {
		cin >> arr[i];
	}

	ll e = 0 ;
	ll doll = 0;
	for (int i = 0; i < n; ++i) {
		int temp = arr[i] - arr[i + 1];
		temp += e;

		if(temp < 0){
			doll += abs(temp);
			e = 0;
		}
		else
			e = temp;
	}
	cout << doll ;
	return 0;
}

