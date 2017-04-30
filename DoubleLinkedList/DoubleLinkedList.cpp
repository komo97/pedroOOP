// DoubleLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DLinkedList.h"

int main()
{
	DLinkedList<std::string> list("Test1");
	DLinkedList<int>* sortedList;
	list.Insert("Test2");
	list.Insert("Test3");
	list.Insert("Test4");
	std::cout << list.GetAtIndex(1)->element << std::endl;
	std::cout << list.GetHead()->index << std::endl;
	std::cout << list.GetTail()->element << std::endl;
	std::cout << list.Search("Test2")->element << std::endl;
	std::cout << list.Count() << std::endl;
	std::cout << list.Contains("Test3") << std::endl;

	list.PrintAll();

	std::string strings[]{ "Test5","Test6","Test7","Test4" };
	list.InsertElements(strings, 4);

	std::cout << std::endl;
	list.PrintAll();

	list.Remove(2);

	std::cout << std::endl;
	list.PrintAll();

	list.Remove("Test5");

	std::cout << std::endl;
	list.PrintAll();

	list.RemoveAll("Test4");

	std::cout << std::endl;
	list.PrintAll();

	list.Reverse();

	std::cout << std::endl;
	list.PrintAll();



	sortedList = new DLinkedList<int>(2);
	sortedList->InsertSorted(1, false);
	sortedList->InsertSorted(3, false);
	sortedList->InsertSorted(7, false);
	sortedList->InsertSorted(23, false);
	sortedList->InsertSorted(9, false);
	sortedList->InsertSorted(12, false);
	sortedList->InsertSorted(4, false);
	sortedList->InsertSorted(8, false);

	std::cout << std::endl;
	sortedList->PrintAll();

	delete sortedList;
	getchar();
	return 0;

}

