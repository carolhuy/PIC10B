#include <iostream>
#include <iomanip>
#include "Complex.h"

using namespace std;

int main()
{
	Complex a(1.5);
	Complex b(3, -1);
	cout << setw(10) << "a = " << a << endl;
	cout << setw(10) << "- b = " << -b << endl;
	cout << setw(10) << "a * b = " << a * b << endl;
	cout << setw(10) << "a / b = " << a / b << endl;
	cout << setw(10) << "a + b = " << a + b << endl;
	cout << setw(10) << "a - b = " << a - b << endl;

	Complex c(0, 3);
	double d = 0.2;
	cout << setw(10) << "c = " << c << endl;
	cout << setw(10) << "d = " << d << endl;
	c += d;
	cout << setw(10) << "c + d = " << c << endl;
	cout << setw(10) << "Real(c) = " << c.real() << endl
		<< setw(10) << "Imag(c) = " << c.imag() << endl;
	cout << c.operator++() << " ";
	cout << ++c << endl;

	return 0;
}

