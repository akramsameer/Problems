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
#define f first
#define s second
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int ydir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void file() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	// online submission
	//freopen("interesting.in", "r", stdin);
#endif
}
int arr[26];
string str;
int main() {
	file();
    cin>> str;
    for(int i = 0 ; i < sz(str) ; i++)
    	arr[str[i]-'a']++;

    int cnt = 0 ;
    for(int  i = 0 ; i < 26 ;i++)
    	if(arr[i] & 1)
    		cnt++;

    cnt--;
    if(cnt & 1 && cnt > 0)
    	printf("Second\n");
    else
    	printf("First\n");

    return 0;
}
