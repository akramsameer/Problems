//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <stdio.h>
#define ll long long
using namespace std;
int top , n , arr[101][2] , rr , rl  ;
bool dice[7];
void clear(){
	for (int i = 1; i < 7; ++i) {
		dice[i] = false;
	}
}
pair<int , int > rem(){
	pair<int , int> ret ;
	ret.first = 0,ret.second = 0;
	for (int i = 1; i < 7; ++i) {
		if(!dice[i]){
			if(ret.first == 0)
				ret.first = i ;
			else if(ret.second == 0)
				ret.second = i;
		}
	}
	return ret;
}
bool isUnique(int ind ){
	clear();
	int revx = 7 - arr[ind][0];
	int revy = 7 - arr[ind][1];
	dice[arr[ind][0]]= true;
	dice[arr[ind][1]]=true;
	dice[revx] = true;
	dice[revy] = true;
	pair<int , int > ans  = rem();
	if(top == ans.first){
		top = ans.first;
		return true;
	}
	else if (top == ans.second){
		top = ans.second;
		return true;
	}
	return false;
}

int main() {
	cin >> n ;
	cin >> top;
	top = 7 - top ;

	for (int i = 0; i < n; ++i)
		cin >> arr[i][0] >> arr[i][1] ;

	bool ans = true;
	for (int i = 0; i < n; ++i) {
		if(!isUnique(i)){
			ans = false;
		}
	}
	if(ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
