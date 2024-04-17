#pragma once
#include <iostream>
#include <cmath>

//using namespace std;

class Complex {
  public:
  
  	double real;
	double imaginary;
  
	Complex(double r, double i);
	Complex(double r);
	Complex();
	
	~Complex();
	
	friend Complex operator+(const Complex &lhs, const Complex &rhs);
	friend Complex operator-(const Complex &lhs, const Complex &rhs);
	friend Complex operator*(const Complex &lhs, const Complex &rhs);
	friend Complex operator/(const Complex &lhs, const Complex &rhs);

	//Complex operator+(Complex const& c);
	//Complex operator-(Complex const& c);
	//Complex operator*(Complex const& c);
	//Complex operator/(Complex & c);
	
	Complex operator+=(Complex c);
	Complex operator-=(Complex c);
	Complex operator*=(Complex c);
	Complex operator/=(Complex c);
	
	//bool operator==(Complex const& c);
	//bool operator!=(Complex const& c);
	
	friend bool operator==(Complex const &lhs, Complex const &rhs);
	friend bool operator!=(Complex const &lhs, Complex const &rhs);
	
	Complex operator-();
	
	double phase();
	double magn();
};

std::ostream& operator<<(std::ostream& , Complex const& c);
