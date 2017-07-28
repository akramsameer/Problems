//============================================================================
// Name        : Working.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

double fixAngle(double A) {
	return A > 1 ? 1 : (A < -1 ? -1 : A);
}

//	sin(A)/a = sin(B)/b = sin(C) / c
double getside_a_bAB(double b, double A, double B) {
	return (sin(A) * b) / sin(B);
}

double getAngle_A_abB(double a, double b, double B) {
	return asin( fixAngle((a * sin(B)) / b) );
}

// 	a^2 = b^2 + c^2 - 2*a*c*cos(A)
double getAngle_A_abc(double a , double b, double c){
	return acos( fixAngle(	(b*b + c*c - a*a)/(2*a*c) ) );
}
