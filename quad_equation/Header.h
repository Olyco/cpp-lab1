#ifndef HEADER_H_INCLUDED__
#define HEADER_H_INCLUDED__
#pragma once

#include <cmath>
#include <clocale>
#include <iostream>​
using namespace std;

class  quad_equation {
public:
	double Discriminant(double A, double B, double C) {
		return B * B - 4 * A * C;
	}
	double AllZeroExceptB(void) {
		return 0;
	}
	double AllNonZeroExceptA(double B, double C) {
		return -C / B;
	}
	double ZeroBPositiveA(void) { 
		return 0;
	}
	double ZeroBExtractedRoot(double A, double C) {
		return sqrt(-C / A);
	}
	double RootFromFirstMultiplier(void) {
		return 0;
	}
	double RootFromSecondMultiplier(double A, double B) {
		return -B / A;
	}
	double FirstDiscriminantRoot(double A, double B, double D) {
		return (-B + sqrt(D)) / (2 * A);
	}
	double SecondDiscriminantRoot(double A, double B, double D) {
		return (-B - sqrt(D)) / (2 * A);
	}
};

#endif  HEADER_H_INCLUDED

