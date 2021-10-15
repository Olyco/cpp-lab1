#pragma once

#include <iostream>
#include <cmath>

struct Solution{
	int numOfRoots;
	double* roots;
};

class  QuadEquation {
private:
	double A;
	double B;
	double C;
public:
	QuadEquation();
	double Discriminant() const;
	Solution Solver() const;
	void PrintAnswer(Solution solution) const;
};
