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
struct book {
	string author, title;
	bool borrowed , returned ;

	book(string a , string b){
		author = a ;
		title = b;
		borrowed = false;
		returned = false;
	}

	bool operator <(const book & e) const {
		if (author == e.author) {
			return title < e.title;
		}
		else
			return author < e.author;
	}
};
void borrow(vector<book> & books){
	string temp ;
	getchar();
	getline(cin  , temp);
	for(int i = 0 ; i < sz(books) ; i++)
		if(books[i].title == temp){
			books[i].borrowed = true;
			books[i].returned = false;
			return ;
		}
}

void returned(vector<book> & books){
	string temp ;
	getchar();
	getline(cin , temp);
	for(int i = 0 ; i < sz(books) ; i++)
		if(books[i].title == temp){
			books[i].returned  = true;
			books[i].borrowed  = false;
			return ;
		}
}
void shelve(vector<book> & books){
	for(int i = 0 ; i < sz(books) ;i++ )
		if(books[i].returned){
			int j;
			for(j = i -1 ;  j >= 0 ; j--)
				if(!books[j].borrowed)
					break;

			if(j == -1)
				printf("Put %s first\n", books[i].title.c_str());
			else
				 printf("Put %s after %s\n",books[i].title.c_str(), books[j].title.c_str());

			books[i].borrowed = books[i].returned = false;
		}
	printf("END\n");
}
int main() {
	file();
	vector<book> books;
	string temp ;
	map<string , int> mp;
	int i = 0;
	while(getline(cin , temp) , temp != "END"){
		string title = temp.substr(0 , temp.find_last_of("\"")+1) , author=  temp.substr(temp.find_last_of("\"")+1);
		books.push_back(book(author, title));
		mp[title] = i++ ;
	}
	sort(books.begin() , books.end());

	while(cin >> temp , temp != "END"){
		if(temp == "BORROW"){
			borrow(books);
		}
		else if(temp == "RETURN")
			returned(books);
		else if(temp == "SHELVE")
			shelve(books);
	}

	return 0;
}












