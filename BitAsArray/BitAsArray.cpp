// BitAsArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

__int8 arr[4096];
void TurnOnBit(const int& index)
{
	if (index > 32768 || index < 1) return;
	arr[(index - 1)/8] |= 1 << ((index - 1) % 8);
}

//Returns 1 on found success, 0 on fail.
int ReadBit(const int& query)
{
	if (query > 32768 || query < 1) return 0;
	return arr[(query - 1) / 8] & (1 << (query - 1) % 8) ? 1 : 0;
}
int main()
{
	memset(arr, 0, 4095);
	std::string a("1");
	int query;
	while (1)
	{
		std::cin >> a;
		if(query = atoi(a.c_str()))
			TurnOnBit(query);
		else break;
	}
	while (1)
	{
		std::cin >> a;
		if (query = atoi(a.c_str()))
			std::cout << (ReadBit(query) ? "Si" : "No") << std::endl;
		else break;
	}
	system("pause");
    return 0;
}

