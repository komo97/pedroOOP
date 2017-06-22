// ArbolDeNavidad.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
void ArbolHorizontal(const int& cols)
{
	int spaces, stars;
	for (int i = 0; i < cols; i++)
	{
		spaces = cols - 1 - i;
		for (int i = spaces; i--;)
			std::cout << " ";
		stars = (i * 2) + 1;
		for (int i = stars; i--;)
			std::cout << "*";
		std::cout << std::endl;
	}
}

void ArbolVertical(const int& cols)
{
	int rows = (cols * 2) - 1, halfway = rows, maxcol = 1;
	for (int i = rows * 2; i--;)
	{
		for (int j = maxcol; j--;)
			std::cout << "*";
		std::cout << std::endl;
		if (i >= halfway)
			++maxcol;
		else maxcol > 0 ? --maxcol : maxcol = 1;
	}
	std::cout << "*" << std::endl;
}
int main()
{
	int cols;
	std::cin >> cols;
	ArbolVertical(cols);
	system("pause");
    return 0;
}

