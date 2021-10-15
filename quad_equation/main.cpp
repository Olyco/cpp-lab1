#include "Header.h"

int main(void) {
	QuadEquation equation;
	Solution solution= equation.Solver();
	equation.PrintAnswer(solution);

	delete solution.roots;
	return 0;
}