// intToString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
std::string IntToString(int val)
{
	std::string ret;
	std::stack<char> vals;
	while (val)
	{
		vals.push((val % 10) + 48);
		val /= 10;
	}
	while (!vals.empty())
	{
		ret += vals.top();
		vals.pop();
	}
	return ret;
}

int main()
{
	int a;
	std::cin >> a;
	std::cout << IntToString(a) << std::endl;
	system("pause");
    return 0;
}

