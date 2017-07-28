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

int main() {
	freopen("in.txt", "r", stdin);

	return 0;
}


// =========================== Counting Technique =======================================
/*
 *  	suppose you have a die s = {1,2,3,4,5,6}
 *  					   and A = {5 , 6}
 *  		then p(A) = n(A)/n(s) = 2/6 = 1/3
 *
 *  	suppose you roll two dice :
 *  						S = {(1,1)(1,2)....(1,6)}
 *  							{(2,1)(2,2)....(2,6)}
 *  							.
 *  							.
 *  							{(6,1)(6,2)....(6,6)}		==> 36
 *
 *  	the benefit is
 *  	- to study methods of finding the number of elements in the sample space or in event without to list
 *  	  all elements
 *
 *  	THE MULTIPLICATION RULE OF COUNTING :
 *
 *  		 suppose you have 3 appalizers ==> A and
 *  		 				  2 courses    ==> C
 *  		 	A1 ==> C1 , C2
 *  		 	A2 ==> C1 , C2
 *  		 	A3 ==> C1 , C2
 *  		 the number of way to choose appalizers and courses is A * C = 6
 *
 *  	     if you have an exeperement	and it done in seperate stages then
 *
 *  	     	stage1 * stage2 * ........ stage k
 *  	     	  n1       n2                nk
 *
 *  			then
 *  				n1 * n2 * ...... * nk
 *
 * 		 	suppose you have a urn and there exist 1 red and 1 blue and 1 green and 1 white
 * 		 	what is the number of possible way if you draw twice with replacement
 *
 * 		 		- the first time you draw from 4 element
 * 		 		- the second time you draw from 4 element (different stages)
 *
 * 		 			so by the multiplication rule the result is
 * 		 				#S = 4*4 = 4^2
 *
 *  		WHAT IF  we draw without replacement
 *  			- the first time you draw from 4 element
 * 		 		- the second time you draw from 3 element (different stages with different sample spaces)
 * 		 		#S = 4 * 3 = 12
 *
 * 			now lets draw k DISTICNT objects from n objects??
 * 			 		 	n , n-1 , n-2 , ...... , n-k+1
 * 			 		 	n(n-1)(n-2)....(n-k+1)
 * 		 	THIS CALLED PERMUTATION OF K OBJECTS FROM N
 *
 * 		 	nPk = !n / !(n-k) where n >= k
 *
 * 		 	ex
 * 		 	  we have 10 atheletes competing in 100 hundrad meter and how many ways can the ranking can be assign
 * 		 	  to the top 3 competotrs  ...
 *
 * 		 	  	- now we have
 * 		 	  					1st , 2nd , 3rd
 * 		 	  					 10 ,  9  ,  8
 * 		 	one of the ten cross the line first 	,  in the 2nd place we have 9 competotrs  , 8
 *
 *
 *
 */








