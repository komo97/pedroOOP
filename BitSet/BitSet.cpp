// BitSet.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void BitSet1(int &intToSet, int position);

void PrintIntAsBit(int num);

int main()
{
	int num, sel;
	std::cout << "Introduce el numero a modificar" << std::endl;
	std::cin >> num;
	PrintIntAsBit(num);

	while (1)
	{
		std::cin >> sel;
		BitSet1(num, sel);
	}

    return 0;
}

void BitSet1(int &intToSet, int position) 
{
	int set = 1 << position - 1;
	intToSet |= set;
	PrintIntAsBit(intToSet);
}

void PrintIntAsBit(int num)
{
	for (int i = 0; i++ < 32;)
	{
		std::cout << num % 2;
		num = num >> 1;
		if (!(i % 4) && i)
			std::cout << " ";
	}
	std::cout << std::endl;
}
