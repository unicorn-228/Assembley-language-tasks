#include <iostream>

using namespace std;

double exp_(double x) {
	double x_fact = x;
	double result = 1.;
	double n_fact = 1.;
	double n = 1.;
	int n_max = 200;
	double null_reg = 0.;
	_asm {
		mov ecx , n_max
		finit
		loop1:
		fld x_fact
		fdiv n_fact
		fadd result
		fstp result
		fld1
		fadd n
		fstp n
		fld x_fact
		fmul x
		fstp x_fact
		fld n_fact
		fmul n
		fstp n_fact
		loop loop1
	}
	return result;
}

void main() {
	cout << exp_(5.) << endl;
	system("pause");
}