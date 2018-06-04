//============================================================================
// Name        : Trie.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string.h>
using namespace std;

const int MAX_CHAR = 26 ;

struct trie {
	trie* child[MAX_CHAR];
	bool isleaf;

	trie(){
		memset(child , 0 , sizeof child);
		isleaf = 0;
	}

	void insert(char *str){
		if(*str == '/0')
			isleaf = 1 ;
		else {
			int cur = *str - 'a';
			if(child[cur] == 0)
				child[cur] = new trie();
			child[cur]->insert(str+1);
		}
	}

	bool wordExist(char *str){
		if(*str == '/0')
			return isleaf;
		int cur = *str - 'a';
		if(child[cur] == 0)
			return false;

		return child[cur] -> wordExist(str+1);
	}

	bool getPrefixExist(char *str){
		if(*str =='/0')
			return true;
		int cur = *str - 'a';
		if(child[cur] == 0)
			return false;

		return child[cur]-> getPrefixExist(str +1);
	}
};

int main() {
	trie root ;

	root.insert("abcd");
	root.insert("xyz");
	root.insert("abf");
	root.insert("xn");
	root.insert("ab");
	root.insert("bcd");

	cout<<root.wordExist("xyz") << endl;
	cout<<root.wordExist("xy") << endl;
	cout<<root.wordExist("xyz") << endl;

	return 0;
}
