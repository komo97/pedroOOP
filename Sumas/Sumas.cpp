// Sumas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

void sum1()
{
	std::string a("1");
	int sum = 0;
	while (atoi(a.c_str()))
	{
		std::cin >> a;
		sum += atoi(a.c_str());
	}
	std::cout << sum;
}

void sum2()
{
	std::string a("1");
	std::vector<int> sum;
	while (atoi(a.c_str()))
	{
		std::cin >> a;
		sum.push_back(atoi(a.c_str()));
	}
	int res = 0;
	for (auto i : sum)
		res += i;
	std::cout << res;
}
int main()
{
	sum2();
	system("pause");
    return 0;
}

