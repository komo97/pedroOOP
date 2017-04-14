// heapSot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

namespace ArrayExt {

	///<summary>
	///Swaps the first element of an array with the second one. Returns false if the size is less than any of the elements index.
	///</summary>
	bool Swap(int* &elements, int sizeArr, int firstElem, int secElem)
	{
		if (sizeArr > firstElem && sizeArr > secElem)
		{
			int savedElem;
			savedElem = elements[firstElem];
			elements[firstElem] = elements[secElem];
			elements[secElem] = savedElem;
			return true;
		}
		return false;
	}

	///<summary>
	///Returns the last non zero element of an int array.
	///</summary>
	int LastNonZeroElem(int *heap, int sizeArr)
	{
		for (int i = 0; i < sizeArr; ++i)
		{
			if (heap[i] == 0)
			{
				return i - 1;
			}
		}
		return sizeArr;
	}

	///<summary>
	///Returns the child in a heap of an index. Returns -1 if the index is a leaf.
	///</summary>
	///<param name= "childNum"> 0 or 1 </param>
	int GetIndexChild(int heapSize, int index, int childNum)
	{
		int i = index * 2 + (childNum == 0 ? 1 : 2);
		if (i >= heapSize)
			return -1;
		return i;
	}

	///<summary>
	///Sifts down an element in a heap
	///</summary>
	bool SiftDown(int *heap, int heapSize, int leafIndex, bool isMax)
	{
		int leaf = heap[leafIndex];
		bool leafisInPlace = false;
		bool changedAtLeastOnce = false;
		while (!leafisInPlace)
		{
			int child1 = GetIndexChild(heapSize, leafIndex, 0);
			int child2 = GetIndexChild(heapSize, leafIndex, 1);
			if (isMax)
			{
				if (child1 != -1)
				{
					if (heap[leafIndex] < heap[child1])
					{
						Swap(heap, heapSize, leafIndex, child1);
						leafIndex = child1;
						changedAtLeastOnce = true;
					}
					else if (child2 != -1 && heap[leafIndex] <= heap[child2])
					{
						Swap(heap, heapSize, leafIndex, child2);
						leafIndex = child2;
						changedAtLeastOnce = true;
					}
					else leafisInPlace = true;
				}
				else leafisInPlace = true;

			}
			else
			{
				if (child1 != -1)
				{
					if (heap[leafIndex] > heap[child1])
					{
						Swap(heap, heapSize, leafIndex, child1);
						leafIndex = child1;
						changedAtLeastOnce = true;
					}
					else if (child2 != -1 && heap[leafIndex] >= heap[child2])
					{
						Swap(heap, heapSize, leafIndex, child2);
						leafIndex = child2;
						changedAtLeastOnce = true;
					}
					else leafisInPlace = true;
				}
				else leafisInPlace = true;
			}
		}
		return changedAtLeastOnce;

	}

	///<summary>
	///Makes an int array into a heap. Runs an extra 2 times for the sake of assurance.
	///</summary>
	void Heapify(int *heap, int heapSize, bool isMax)
	{
		int j = 2;
		while (j--)
		{
			for (int i = 0; i < heapSize; ++i)
			{
				if (SiftDown(heap, heapSize, i, isMax))
					i = 0;
			}
		}
	}

	///<summary>
	///Inserts an element into a heap. Calls the Heapify routine. If an array does not hold enough elements it creates a new array with size + 1.
	///</summary>
	void InsertInHeap(int *&heap, int &heapSize, int newElement, bool isMax)
	{
		if (ArrayExt::LastNonZeroElem(heap, heapSize) == heapSize) {
			int *copyHeap = new int[heapSize + 1];
			for (int i = 0; i < heapSize; i++)
			{
				copyHeap[i] = heap[i];
			}
			heap = copyHeap;
			heapSize += 1;
		}

		heap[heapSize - 1] = newElement;

		Heapify(heap, heapSize, isMax);
	}

	///<summary>
	///Sorts a heap.
	///</summary>
	void HeapSort(int *heap, int heapSize, bool isMax)
	{
		int count = heapSize - 1;
		while (count > 0)
		{
			Swap(heap, count + 1, 0, count);
			--count;
			Heapify(heap, count + 1, isMax);
		}
	}

}

int main()
{
	int *arr = new int[10];
	int size = 10;
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = std::rand() % 20;
	}
	ArrayExt::InsertInHeap(arr, size, 15, false);

	for (int i = 0; i < size; ++i)
	{
		printf_s("%d ", arr[i]);
	}
	printf_s("\n");

	ArrayExt::HeapSort(arr, size, false);
	//ArrayExt::InsertInHeap(arr, size, 9, true);
	for (int i = 0; i < size; ++i)
	{
		printf_s("%d ", arr[i]);
	}
    return 0;
}

