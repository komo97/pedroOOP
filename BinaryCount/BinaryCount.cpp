// BinaryCount.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

int BitCount(int n);

int main()
{
	int num;
	scanf_s("%d%*c", &num);
	printf_s("%d", BitCount(num));

    return 0;
}

int BitCount(int n) {
	int val = n, count = 0;
	while (val)
	{
		if ((val % 2) == 1)
			++count;
		val = val >> 1;
	}
	return count;
}

