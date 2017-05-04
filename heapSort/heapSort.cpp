// heapSot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include "TLinkedList.h"
#include "DLinkedList.h"
#include "DNode.h"

typedef struct Tree
{
	int value;
	DLinkedList<Tree> *nodes = NULL;
	Tree* parentTree = NULL;

}Tree;

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

	int GetIndexParent(int index)
	{
		return (index % 2) ? (index - 1) / 2 : (index - 2) / 2;
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

	bool IsBinTreeArr(int *arr, const int& size) {
		if (arr == NULL)
			return false;
		std::stack<int> arrIndexes;
		int saveForSwap;
		arrIndexes.push(0);
		while (arrIndexes.size()) {
			if (GetIndexChild(size, arrIndexes.top(), 0) == -1)
			{
				arrIndexes.pop();
				do
				{
					saveForSwap = arrIndexes.top();
					arrIndexes.pop();
				} while (GetIndexChild(size, saveForSwap, 1) == -1 && arrIndexes.size() != 0);
				if (arrIndexes.size() == 0) break;
				if (arr[GetIndexChild(size, saveForSwap, 1)] < arr[saveForSwap])
					return false;
				arrIndexes.push(GetIndexChild(size, saveForSwap, 1));
			}
			else {
				if (arr[GetIndexChild(size, arrIndexes.top(), 0)] > arr[arrIndexes.top()])
				{
					return false;
				}
				arrIndexes.push(GetIndexChild(size, arrIndexes.top(), 0));
			}

		}
		return true;
	}

	bool IsBinTreeDLinkList(DLinkedList<Tree> *arr) {
		if (arr == NULL)
			return false;
		std::stack<DNode<Tree> *> arrIndexes;
		DNode<Tree>* saveForSwap = NULL;
		arrIndexes.push(arr->GetAtIndex(0));
		while (arrIndexes.size()) {
			if (arrIndexes.top()->element.nodes == NULL)
			{
				arrIndexes.pop();
				do
				{
					saveForSwap = arrIndexes.top();
					arrIndexes.pop();
				} while (saveForSwap->element.nodes->GetAtIndex(1) == NULL && arrIndexes.size() != 0);
				if (arrIndexes.size() == 0) break;
				if (saveForSwap->element.nodes->GetAtIndex(1)->element.value < saveForSwap->element.value)
					return false;
				arrIndexes.push(saveForSwap->element.nodes->GetAtIndex(1));
			}
			else {
				if (arrIndexes.top()->element.nodes->GetAtIndex(0)->element.value > arrIndexes.top()->element.value)
				{
					return false;
				}
				arrIndexes.push(arrIndexes.top()->element.nodes->GetAtIndex(0));
			}
			//if (arrIndexes.top()->element.nodes->Count() > 2) return false;

		}
		return true;
	}

}

int main()
{
	int *arr = new int[10];
	int *arr2 = new int[11] { 6, 2, 7, 1, 3, 4, 9, 0, 5, 2, 9 };
#pragma region lista test
	DLinkedList<Tree> list{ Tree() };
	Tree *node;
	node = &list.GetAtIndex(0)->element;
	node->value = 6;
	node->nodes = new DLinkedList<Tree>(Tree());
	node->nodes->GetAtIndex(0)->element.value = 2;
	node->nodes->GetAtIndex(0)->element.nodes = new DLinkedList<Tree>(Tree());
	node->nodes->GetAtIndex(0)->element.parentTree = node;
	node->nodes->Insert(Tree());
	node->nodes->GetAtIndex(1)->element.value = 7;
	node->nodes->GetAtIndex(1)->element.nodes = new DLinkedList<Tree>(Tree());
	node->nodes->GetAtIndex(1)->element.parentTree = node;
	node = &node->nodes->GetAtIndex(0)->element;
	node->nodes->GetAtIndex(0)->element.value = 1;
	node->nodes->GetAtIndex(0)->element.nodes = new DLinkedList<Tree>(Tree());
	node->nodes->GetAtIndex(0)->element.parentTree = node;
	node->nodes->Insert(Tree());
	node->nodes->GetAtIndex(1)->element.value = 3;
	node->nodes->GetAtIndex(1)->element.nodes = new DLinkedList<Tree>(Tree());
	node->nodes->GetAtIndex(1)->element.parentTree = node;
	node = &node->parentTree->nodes->GetAtIndex(1)->element;
	node->nodes->GetAtIndex(0)->element.value = 4;
	node->nodes->GetAtIndex(0)->element.nodes = new DLinkedList<Tree>(Tree());
	node->nodes->GetAtIndex(0)->element.parentTree = node;
	node->nodes->Insert(Tree());
	node->nodes->GetAtIndex(1)->element.value = 9;
	node->nodes->GetAtIndex(1)->element.nodes = new DLinkedList<Tree>(Tree());
	node->nodes->GetAtIndex(1)->element.parentTree = node;
	node = &node->parentTree->nodes->GetAtIndex(0)->element.nodes->GetAtIndex(0)->element;
	node->nodes->GetAtIndex(0)->element.value = 0;
	node->nodes->GetAtIndex(0)->element.nodes = new DLinkedList<Tree>(Tree());
	node->nodes->GetAtIndex(0)->element.parentTree = node;
	node->nodes->Insert(Tree());
	node->nodes->GetAtIndex(1)->element.value = 5;
	node->nodes->GetAtIndex(1)->element.nodes = new DLinkedList<Tree>(Tree());
	node->nodes->GetAtIndex(1)->element.parentTree = node;
	node = &node->parentTree->nodes->GetAtIndex(1)->element;
	node->nodes->GetAtIndex(0)->element.value = 2;
	node->nodes->GetAtIndex(0)->element.nodes = new DLinkedList<Tree>(Tree());
	node->nodes->GetAtIndex(0)->element.parentTree = node;
	node->nodes->Insert(Tree());
	node->nodes->GetAtIndex(1)->element.value = 9;
	node->nodes->GetAtIndex(1)->element.nodes = new DLinkedList<Tree>(Tree());
	node->nodes->GetAtIndex(1)->element.parentTree = node;

#pragma endregion

	int size = 10;
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = std::rand() % 20;
	}
	ArrayExt::InsertInHeap(arr, size, 15, true);

	for (int i = 0; i < size; ++i)
	{
		printf_s("%d ", arr[i]);
	}
	printf_s("\n");

	ArrayExt::HeapSort(arr, size, true);
	
	std::cout << "Arr2 is BST:"<<( ArrayExt::IsBinTreeArr(arr2, 11)  ? "TRUE" : "FALSE") << std::endl;
	std::cout << "lista is BST:" << (ArrayExt::IsBinTreeDLinkList(&list) ? "TRUE" : "FALSE") << std::endl;

	ArrayExt::InsertInHeap(arr, size, 9, true);
	for (int i = 0; i < size; ++i)
	{
		printf_s("%d ", arr[i]);
	}
    return 0;
}

