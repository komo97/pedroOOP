// BinarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <functional>
static int BinarySearch(int* const& arr, const int& size, const int& val)
{
	int lb = 0, ub = size - 1, temp;
	while (lb != ub)
	{
		temp = lb + ((ub - lb) / 2);
		if (arr[temp] == val)
			return temp;
		else if (arr[temp] < val)
			lb = temp;
		else
			ub = temp;
	}
	return -1;
}

int main()
{
	std::vector<int> arr;
	std::string a("1");
	int query;
	while (atoi(a.c_str()))
	{
		std::cin >> a;
		arr.push_back(atoi(a.c_str()));
	}
	std::cout << "Que numero vas a buscar?" << std::endl;
	std::cin >> query;
	std::cout << "Se encuentra en el indice: " << BinarySearch(arr.data(), arr.size(), query) << std::endl;
	system("pause");
    return 0;
}

