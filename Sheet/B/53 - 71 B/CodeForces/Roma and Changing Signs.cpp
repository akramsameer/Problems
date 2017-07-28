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
int n , k , arr[10001];
int main() {
	freopen("in.txt", "r", stdin);
	cin >> n  >> k ;
	for(int i = 0 ; i < n ;i++)
		cin>> arr[i];

	int ind1 = 0 , ind2 = n-1;
	while(ind1 < ind2 && k){
		if(abs(arr[ind1]) > abs(arr[ind2])){    ///    [0]
			if(arr[ind1] < 0){
				arr[ind1] *= -1;
				k--;
				ind1++;
			}
			else
				ind1++;
		}
		else if(abs(arr[ind1]) == abs(arr[ind2])){
			if(arr[ind1] < 0){
				arr[ind1] *= -1;
				k--;
				ind1++;
			}
			else  if (arr[ind2] < 0){
				arr[ind2] *= -1;
				k--;
				ind2--;
			}
			else
				ind1++;
		}
		else{
			if(arr[ind2] < 0){
				arr[ind2] *= -1;
				k--;
				ind2--;
			}
			else
				ind2--;
		}
	}
	int m = min_element(arr , arr+n)-arr;
	while(k--){
		arr[m] *= -1;
	}
	ll  sum = 0;
	for(int i = 0 ; i < n ; i++ )
		sum += arr[i];

	cout<<sum <<endl;
}
