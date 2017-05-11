#pragma once
#include <iostream>
#include <string>
class Complex
{
private:
	float real,
		imag;
public:
	Complex();
	Complex(const float& r, const float& i);
	Complex(const Complex& c);
	Complex& operator = (const Complex& c);
	Complex operator + (const Complex& c) const;
	Complex operator - (const Complex& c) const;
	Complex operator * (const Complex& c) const;
	Complex operator / (const Complex& c) const;
	Complex &operator += (const Complex& c);
	Complex &operator -= (const Complex& c);
	Complex &operator *= (const Complex& c);
	Complex &operator /= (const Complex& c);
	friend std::istream& operator>> (std::istream& rhs, Complex& a);
	std::string print();
};

