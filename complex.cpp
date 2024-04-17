#include "complex.h"
#include <iostream>
#include <ostream>

using namespace std;

Complex::Complex(double r, double i)
{
	real = r;
	imaginary = i;
}
Complex::Complex()
{
	real = 0;
	imaginary = 0;
}
Complex::Complex(double r)
{
	real = r;
	imaginary = 0;
}

Complex::~Complex() {}

ostream& operator<<(ostream& os, Complex const& c)
{
	if (c.imaginary > 0) {
		os << c.real << "+" << c.imaginary << 'i';
	}
	else {
		os << c.real << c.imaginary << 'i';
	}
	return os;
}

Complex Complex::operator-()
{
	return (Complex(this->real, -(this->imaginary)));
}

/*Complex Complex::operator+(Complex const& c)
{
	Complex number;
	number.real = this->real + c.real;
	number.imaginary = this->imaginary + c.imaginary;
	return number;
}*/

Complex operator+(const Complex& lhs, const Complex& rhs)
{
	Complex number;
	number.real = lhs.real + rhs.real;
	number.imaginary = lhs.imaginary + rhs.imaginary;
	return number;
}

/*Complex operator-(Complex const &lhs, const Complex &rhs)
{
	Complex number;
	number.real = this->real - c.real;
	number.imaginary = this->imaginary - c.imaginary;
	return number;
}*/

Complex operator-(Complex const& lhs, const Complex& rhs)
{
	Complex number;
	number.real = lhs.real - rhs.real;
	number.imaginary = lhs.imaginary - rhs.imaginary;
	return number;
}

/*Complex Complex::operator*(Complex const &c)
{
	Complex number;
	number.real = this->real * c.real + this->imaginary * c.imaginary * -1;
	number.imaginary = this->real * c.imaginary + this->imaginary * c.real;
	return number;
}*/

Complex operator*(Complex const& lhs, Complex const& rhs)
{
	Complex number;
	number.real = lhs.real * rhs.real + lhs.imaginary * rhs.imaginary * -1;
	number.imaginary = lhs.real * rhs.imaginary + lhs.imaginary * rhs.real;
	return number;
}

/*Complex Complex::operator/(Complex &c)
{
	Complex number;
	Complex conjugate = -c;

	Complex numerator = *this * conjugate;
	Complex denumerator = c * conjugate;
	number.real = numerator.real / denumerator.real;
	number.imaginary = numerator.imaginary / denumerator.real;
	return number;
}*/

Complex operator/(Complex& lhs, Complex& rhs)
{
	Complex number;
	Complex conjugate = -rhs;

	Complex numerator = lhs * conjugate;
	Complex denumerator = rhs * conjugate;
	number.real = numerator.real / denumerator.real;
	number.imaginary = numerator.imaginary / denumerator.real;
	return number;
}

Complex Complex::operator+=(Complex c)
{
	*this = *this + c;
	return *this;
}

Complex Complex::operator-=(Complex c)
{
	*this = *this - c;
	return *this;
}

Complex Complex::operator*=(Complex c)
{
	*this = *this * c;
	return *this;
}

Complex Complex::operator/=(Complex c)
{
	*this = *this / c;
	return *this;
}

/*bool Complex::operator==(Complex const& c)
{
	if (this->real != c.real){
		return false;
	}

	if (this->imaginary != c.imaginary)
	{
		return false;
	}
	return true;
}*/

bool operator==(Complex const& lhs, Complex const& rhs)
{
	if (lhs.real != rhs.real) {
		return false;
	}

	if (lhs.imaginary != rhs.imaginary) {
		return false;
	}
	return true;
}

/*bool Complex::operator!=(Complex const& c)
{
	if (*this == c){
		return false;
	}
	return true;
}*/

bool operator!=(Complex const& lhs, Complex const& rhs)
{
	if (lhs == rhs) {
		return false;
	}
	return true;
}

double Complex::phase()
{
	if (this->real != 0) {
		return atan(this->imaginary / this->real);
	}
	else {
		cout << "cant divide by 0!";
		return 0;
	}
}

double Complex::magn()
{
	return hypot(this->imaginary, this->real);
}
