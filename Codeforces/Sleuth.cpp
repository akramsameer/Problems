//============================================================================
// Name        : Sleuth.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;
string str;
char vowel[12]{'a' , 'e' , 'i' , 'o' , 'u' , 'y' , 'A' , 'E' , 'I', 'O' , 'U' , 'Y'};
bool isVowel(char c){
	for(int i = 0 ; i< 12 ;i++)
		if(c == vowel[i])
			return true;
	return false;
}
int main() {
	getline(cin , str);

	int i = str.length() -1;
	while(i){
		if(str[i] != '?' && str[i] != ' ')
			break;
		i--;
	}
	cout <<((isVowel(str[i]))?"YES" : "NO" )<<endl;
	return 0;
}
