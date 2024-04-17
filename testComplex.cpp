#include "complex.h"
#include <iostream>

using namespace std;

int main()
{
	Complex a(1, 1);
	Complex b(5, 2);
	Complex c(3, 3);

	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	// a += (b += c);
	// c = a / b;

	//(a += b) += c;

	// a *= b *= c;
	//(a *= b) *= c;
	// a + 7;
	// 7 + a;
	// b * 5;
	// 5 * b;
	// c == 3.5;
	//3.5 == c;
	
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	return 0;
}
