//============================================================================
// Name        : .cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
int n ;
int main() {
	cin>> n ;
	int min= 0 , max=0 ;
	int i = n ;
	int cnt = 0;
	while(i > 0){
		if(cnt & 1){
			i-=1;
			min+=1;
			if (min %2 == 0)
				cnt++;
		}
		else{
			i -=5;
			cnt++;
		}

	}
	i = n ;
	cnt = 0;
	while(i > 0){
		if(cnt & 1){
			i-=5;
			cnt++;
		}
		else{
			i -=1;
			max +=1;
			if(max % 2 == 0)
				cnt++;
		}

	}
	cout<<min<< " "<<max<<endl;

	return 0;
}
