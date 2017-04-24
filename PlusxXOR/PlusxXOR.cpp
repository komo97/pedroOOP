// PlusxXOR.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <vector>

void PrintBits(unsigned long int num);
///<summary0>
///0 Based.
///</summary>
int LastStateInSet(unsigned long int num, int onOff);
int FirstStateInSet(unsigned long int num, int onOff);
int NumOfStatesInSet(unsigned long int num, int onOff);
unsigned long int XORPlusComboNum(unsigned long int num);
bool VectorContains(std::vector<unsigned long int> num, unsigned long int val);
std::vector<unsigned long int> XORPlusComboList(unsigned long int num);

int main()
{
	int num;
	int* arrIndexes;
	std::cin >> num;
	PrintBits(num);
	std::cout << std::endl << LastStateInSet(num, 1);
	std::cout << std::endl << NumOfStatesInSet(num, 1);
	std::cout << std::endl << XORPlusComboNum(NumOfStatesInSet(num, 0));
	std::cout << std::endl << FirstStateInSet(num, 0) << std::endl;

	std::vector<unsigned long int> res = XORPlusComboList(num);

	for (int i = 0; i < res.size(); ++i)
		std::cout << res[i] << std::endl;

    return 0;
}

void PrintBits(unsigned long int num)
{
	for (int i = 31; i--;)
	{
		std::cout << (num & 1);
		num = num >> 1;
	}
}

int LastStateInSet(unsigned long int num, int onOff)
{
	int stateNum = 0;
	for (int i = 0; i < 32; ++i)
	{
		if (!onOff ? !(num & 1) : (num & 1))
			stateNum = i;
		num = num >> 1;
	}
	return stateNum;
}

int FirstStateInSet(unsigned long int num, int onOff)
{
	for (int i = 0; i < 32; ++i)
	{
		if (!onOff ? !(num & 1) : (num & 1))
			return i;
		num = num >> 1;
	}
	return 0;
}

int NumOfStatesInSet(unsigned long int num, int onOff)
{
	int count = 0;
	while (num)
	{

		if (!onOff ? !(num & 1) : (num & 1))
			++count;
		num = num >> 1;

	}
	return count;
}

unsigned long int XORPlusComboNum(unsigned long int ZeroNum)
{
	return pow(2, ZeroNum);
}

bool VectorContains(std::vector<unsigned long int> num, unsigned long int val)
{
	for (int i = 0; i < num.size(); ++i)
	{
		if (num[i] == val)
			return true;
	}
	return false;
}

std::vector<unsigned long int> XORPlusComboList(unsigned long int num)
{
	std::vector<unsigned long int> indexes, values;
	unsigned long int copyNum = num;
	values.push_back(0);
	unsigned long int comboNum = XORPlusComboNum(NumOfStatesInSet(num, 0));
	for (int i = comboNum - 1; i--; )
	{
		indexes.push_back(FirstStateInSet(num, 0));
		for (int i = 0; i < indexes.size(); ++i)
		{
			int mask = 1;
			mask = mask << indexes[i];
			num ^= mask;
			if(num != copyNum && !VectorContains(values,num))
				values.push_back(num);
		}
	}
	return values;
}


