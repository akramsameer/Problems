//============================================================================
// Name        : Product.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Bigint {
	string a; //to store digits
	int sign;
	Bigint() {
	}
	Bigint(string b) {
		*this = b;
	}
	int size() {
		return a.size();
	}
	Bigint inverseSign() { //change the sign
		sign *= -1;	  //inverse the sign
		return (*this);
	}

	Bigint normalize(int newSign) {
		for (int i = a.size() - 1; i > 0 && a[i] == '0'; i--) {
			a.erase(a.begin() + i);
		}
		sign = (a.size() == 1 && a[0] == '0') ? 1 : newSign;
		return (*this);
	}

	void operator =(string b) {
		a = (b[0] == '-') ? b.substr(1) : b;
		reverse(a.begin(), a.end());
		this->normalize(b[0] == '-' ? -1 : 1);
	}

	bool operator <(const Bigint &b) const {
		if (sign != b.sign)
			return sign < b.sign;

		if (a.size() != b.a.size())
			return sign == 1 ? a.size() < b.a.size() : a.size() > b.a.size();

		for (int i = a.size() - 1; i >= 0; i--)
			if (a[i] != b.a[i])
				return sign == 1 ? a[i] < b.a[i] : a[i] > b.a[i];
		return false;
	}

	bool operator ==(const Bigint &b) const {
		return a == b.a && sign == b.sign;
	}

	Bigint operator +(Bigint b) {	//addition operator overloading
		if (sign != b.sign)
			return (*this) - b.inverseSign();
		Bigint c;
		for (int i = 0, carry = 0; i < a.size() || i < b.size() || carry; i++) {
			carry += (i < a.size() ? a[i] - 48 : 0)
					+ (i < b.a.size() ? b.a[i] - 48 : 0);
			c.a += (carry % 10 + 48);
			carry /= 10;
		}
		return c.normalize(sign);
	}

	Bigint operator -(Bigint b) {
		if (sign != b.sign)
			return (*this) + b.inverseSign();
		int s = sign;
		sign = b.sign = 1;
		if ((*this) < b)
			return ((b - (*this)).inverseSign()).normalize(-s);
		Bigint c;
		for (int i = 0, borrow = 0; i < a.size(); i++) {
			borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
			c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
			borrow = borrow >= 0 ? 0 : 1;
		}
		return c.normalize(s);
	}
	Bigint operator *(Bigint b) {
		Bigint c("0"), d;
		for (int i = 0, k = a[i] - 48; i < a.size(); i++, k = a[i] - 48) {
			while (k--)
				c = c + b; //i'th digit is k , so we add k times
			b.a.insert(b.a.begin(), '0');
		}
		return c.normalize(sign*b.sign);
	}

	void print() {
		if (sign == -1)
			putchar('-');
		for (int i = a.size() - 1; i >= 0; i--)
			putchar(a[i]);
	}
};
string x, y;
int arr[251];
int main() {
	Bigint a , b , c;
	while(cin >> x >> y){
		a= x;
		b = y;
		c = a*b;
		c.print();
		cout<<endl;
	}
	return 0;
}
