#include "Header.h"

QuadEquation::QuadEquation() {
	std::cout << "Enter space-separated coefficients:\n";
	std::cin >> A;
	std::cin >> B;
	std::cin >> C;
}

double QuadEquation::Discriminant() const {
	return B * B - 4 * A * C;
}

Solution QuadEquation::Solver() const {
	double x = 0.0, x1 = 0.0, x2 = 0.0;
	Solution solution;
	solution.numOfRoots = 0;
	if (A == 0) {
		if (B == 0) {
			if (C == 0)
				solution.numOfRoots = 3; //Inf number of roots
			else
				solution.numOfRoots = 0; //No roots
		}
		else {
			if (C == 0)
				x = 0;
			else
				x = -C / B;
			solution.numOfRoots = 1;
		}
	}
	else{
		if (B == 0){
			if (C == 0){
				x = 0;
				solution.numOfRoots = 1;
			}
			else{
				if (A < 0) {
					x1 = sqrt(-C / A);
					x2 = -sqrt(-C / A);
					solution.numOfRoots = 2;
				}
				else
					solution.numOfRoots = 0; //x^2 < 0
			}
		}
		else{
			if (C == 0){
				x1 = 0;
				x2 = -B / A;
				solution.numOfRoots = 2;
			}
			else{
				double D = Discriminant();
				if (D < 0)
					solution.numOfRoots = 0;
				else if (D == 0){
					solution.numOfRoots = 1;
					x = -B / 2;
				}
				else{
					solution.numOfRoots = 2;
					x1 = (-B + sqrt(D)) / (2 * A);
					x2 = (-B - sqrt(D)) / (2 * A);
				}
			}
		}
	}
	if (solution.numOfRoots != 0) { 
		solution.roots = new double[solution.numOfRoots]; 
		if (solution.numOfRoots == 1)
			solution.roots[0] = x;
		else {
			solution.roots[0] = x1;
			solution.roots[1] = x2;
		}
	}

	return solution;
}

void QuadEquation::PrintAnswer(Solution solution) const {
	std::cout << A << "x^2 + ";
	if (B < 0)
		std::cout << "(" << B << ")";
	else 
		std::cout << B;
	std::cout << "x + ";
	if (C < 0)
		std::cout << "(" << C << ")";
	else
		std::cout << C;
	std::cout << " = 0 solution:\n";
	if (solution.numOfRoots == 1)
		std::cout << solution.roots[0] << "\n";
	else if (solution.numOfRoots == 2)
	{
		if (solution.roots[0] > solution.roots[1])
			std::cout << solution.roots[0] << "; " << solution.roots[1] << "\n";
		else
			std::cout << solution.roots[1] << "; " << solution.roots[0] << "\n";
	}
	else if (solution.numOfRoots == 0)
		std::cout << "No roots\n";
	else if (solution.numOfRoots == 3)
		std::cout << "Infinite number of solutions\n";
}