#include <iostream>

const int sizeOfInt = 32;
const int signMask = 0x80000000;
const int maxInt = 0x7FFFFFFF;
inline int abs(const int& a) { return a >= 0 ? a : 0 - a; }
inline int ChangeSign(const int& a) { return 0 - a; }
int mult(const int& a, const int &b);

int main()
{
	int a, b;
	std::cin >> a >> b;
	std::cout << mult(a, b);
	return 0;
}

int mult(const int& a, const int &b)
{
	if(a == 0 || b == 0) return 0;
	if(a == 1) return a;
	else if( b == 1) return b;
	int m = (a < 0 && b < 0) || (a > 0 && b < 0) ? ChangeSign(a) : a,
		s = abs(b),
		r = 0;
	for(int i = s; i--;)
		r += m;
	return r;
}