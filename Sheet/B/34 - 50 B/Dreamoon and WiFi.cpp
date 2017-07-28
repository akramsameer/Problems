#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long int
using namespace std;
const int VISITED = 1;
const int UNVISITED = -1;
const long long OO = 1e12;
const int OOI = 1e9;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int xdir[] = { 1, -1, 0, 0 };
int ydir[] = { 0, 0, 1, -1 };
string str1 , str2  ;
int end_pos , tot , num;
int final_pos(string str){
	int ret = 0 ;
	for (int i = 0; i < str.length(); ++i) {
		if(str[i] == '+')
			ret++;
		else
			ret--;
	}
	return ret;
}

void solve(int ind , int size){
	if(!size){
		tot++;
		if(final_pos(str2) == end_pos)
			num++;
		return ;
	}
	for(int i = ind+1 ; i < str2.length() ; i++){
		if(str2[i]=='?'){
			str2[i] = '+';
			solve(i , size-1);
			str2[i] = '-';
			solve(i , size-1);
			str2[i] = '?';
		}

	}
}


int main() {
	freopen("in.txt", "r", stdin);
	cin >> str1 >> str2 ;
	end_pos = final_pos(str1);
	int sz = 0;
	for(int i = 0;i < str2.length(); i++){
		if(str2[i] == '?')
			sz++;
	}
	solve(-1 , sz);
	double res = (double)num/tot;
	cout<<fixed<<setprecision(12)<<res<<endl;
	return 0;
}
