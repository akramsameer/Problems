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

/*GCD :: Greatest Common Divisor
 * gcd(45 , 10) = 5 then 45 % 5 = 10 % 5 = 0;
 *
 * Fact
 * if a % n  = 0 & b % n = 0	 THEN  		(a+b)%n = 0 & (a-b)%n = 0
 *
 * THEN
 * gcd(45 , 10) = gcd (35 , 10) = gcd(25 , 10) = gcd(15 , 10) = gcd(5 , 10)
 * gcd(10 , 5 ) = gcd(5 , 5) = gcd(5 , 0) =  5
 *
 *
 * wait ::
 * 			we just keep the reaming the small from the bigger , the big number turn to the smaller , and then do reverse
 * 			lets make it faster ==>   gcd(45 % 10 , 10) -> simply remove the smaller cycle in 1 step
 * 			then code become easy
 *
 * */
int GCD(int a , int b){
	if(b == 0)
		return a;

	return GCD(b , a%b);
}

/*What about LCM :: Least common multiple
 * That is the first multiple of 2
 * Let's do some prime representation for number a , b
 * a = 2^3 * 7^6
 * b = 2^5 * 7^2
 *
 * to get gcd, we need min of powers of 2 and min of power of 7
 * gcd = 2^max(3,5) * 7^max(6,2)
 *
 * what about lcm ? we need max of powers
 *
 * now .. given gcd(a , b) how to get lcm(a , b)
 *
 * look
 * 		a*b = 2^(3+5) * 7^(6+2)
 * 		gcd = 2^min(3 , 5) * 7 ^ min(6 , 2)
 *
 * 		then
 * 			we need to do subtract the minimum of power from the addition of power give us maximum
 * 			lcm = (a * b) / gcd    ==> will give us the maximum power
 * /



