#include "Header.h"
int main(void) {
	//setlocale(LC_ALL, "rus");
	quad_equation equation;
	double A = 0, B = 0, C = 0, D = 0, x = 0, x1 = 0, x2 = 0;
	int number = 0;
	cout << "Enter coefficients:\n";
	cin >> A;
	cin >> B;
	cin >> C;

	D = equation.Discriminant(A,B,C);
	//cout << "Дискриминант = " << D << endl;

	if (A == 0){
		if (B == 0){
			if (C == 0)
				number = 3; //Any number
			else
				number = 0; //No roots
		}
		else{
			if (C == 0)
				x = equation.AllZeroExceptB();
			else
				x = equation.AllNonZeroExceptA(B,C);
			number = 1;

		}
	}
	else{
		if (B == 0){
			if (C == 0 && A > 0){
				x = equation.ZeroBPositiveA();
				number = 1;
			}
			else{
				number = 2;
				x1 = equation.ZeroBExtractedRoot(A,C);
				x2 = -equation.ZeroBExtractedRoot(A, C);
			}
		}
		else{
			if (C == 0){//cancel out the common multiplier
				x1 = equation.RootFromFirstMultiplier();
				x2 = equation.RootFromSecondMultiplier(A,B);
				number = 2;
			}
			else{
				if (D < 0)
					number = 0;
				else if (D == 0){
					number = 1;
					x = equation.FirstDiscriminantRoot(A,B,D);
				}
				else{
					number = 2;
					x1 = equation.FirstDiscriminantRoot(A,B,D);
					x2 = equation.SecondDiscriminantRoot(A,B,D);
				}
			}
		}
	}
	cout << "Answer:\n";
	if (number == 1)
		cout << x << endl;
	else if (number == 2)
	{
		if (x1 > x2)
			cout << x1 << "; " << x2 << endl;
		else
			cout << x2 << "; " << x1 << endl;
	}
	else if (number == 0)
		cout << "No roots\n";
	else if (number == 3)
		cout << "Infinite number of solutions\n";
	return 0;
}