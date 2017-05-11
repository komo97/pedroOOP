// Complex.cpp : Defines the entry point for the console application.
//
#include "Complex.h"

Complex::Complex()
{
	real = imag = 0;
}

Complex::Complex(const float & r, const float & i)
{
	real = r;
	imag = i;
}

Complex::Complex(const Complex & c)
{
	imag = c.imag;
	real = c.real;
}

Complex & Complex::operator=(const Complex & c)
{
	if (&c == this)
		return *this;
	imag = c.imag;
	real = c.real;
	return *this;
	// TODO: insert return statement here
}

Complex Complex::operator+(const Complex & c) const
{
	return Complex(this->real + c.real, this->imag+c.imag);
}

Complex Complex::operator-(const Complex & c) const
{
	return Complex(this->real - c.real, this->imag - c.imag);
}

Complex Complex::operator*(const Complex & c) const
{
	return Complex(this->real * c.real, this->imag * c.imag);
}

Complex Complex::operator/(const Complex & c) const
{
	return Complex(this->real / c.real, this->imag / c.imag);
}

Complex & Complex::operator+=(const Complex & c)
{
	*this = *this + c;
	return *this;
}

Complex & Complex::operator-=(const Complex & c)
{
	*this = *this - c;
	return *this;
}

Complex & Complex::operator*=(const Complex & c)
{
	*this = *this * c;
	return *this;
}

Complex & Complex::operator/=(const Complex & c)
{
	*this = *this / c;
	return *this;
}

std::string Complex::print()
{
	std::string c = "[" + std::to_string(real) + "," + std::to_string(imag) + "]";
	std::cout << c << std::endl;
	return c;
}

std::istream& operator>>(std::istream & lhs, Complex & rhs)
{
	lhs >> rhs.real >> rhs.imag;
	return lhs;
}
