// ConversionDeBases.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>

char* ChangeBase(int num, const int& base)
{
	if (base < 2 || base > 34) return nullptr;
	std::stack<int> pile;
	while (num)
	{
		pile.push(num%base);
		num /= base;
	}
	int size = pile.size();
	char* res = new char[size];
	for (int i = 0; i < size; ++i)
	{
		res[i] = (pile.top() >= 10 ? 65 + (pile.top() - 10) : 48 + pile.top());
		pile.pop();
	}
	return res;
}

int main()
{
	int num, base;
	std::cin >> num >> base;
	std::cout << ChangeBase(num, base) << std::endl;
	system("pause");
    return 0;
}

