#include "Complex.h"
#include <iostream>

int main()
{
	Complex x, y;
	char sel;
	while (1)
	{
		std::cout << "Val1: ";
		std::cin >> x;
		std::cout << "Operation: ";
		std::cin >> sel;
		std::cout << "Val2: ";
		std::cin >> y;
		switch (sel)
		{
		case '+':
			(x + y).print();
			break;
		case '-':
			(x - y).print();
			break;
		case '*':
			(x * y).print();
			break;
		case '/':
			(x / y).print();
			break;
		default:
			return 0;
		}
	}
	return 0;
}
