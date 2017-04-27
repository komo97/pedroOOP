// LinkedLists.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

template<class T> class LinkedList {

public:
	LinkedList();
	LinkedList(const T& _element);

public:
	T element;
	int Count();
	void Insert(const T& newElement);
	void Remove(const unsigned int& _index);
	void Remove(const T& elementToRemove);
	void RemoveAll(const T& elementToRemove);
	LinkedList<T>* GetAtIndex(const unsigned int& _index);
	bool Contains(const T& _element);
	LinkedList<T>* Search(const T& _element);
	void InsertSorted(const T& newElement, bool lessVal);
	void InsertElements(const T* elements, unsigned int size);
	LinkedList<T>* Reverse();
	void PrintAll();
	LinkedList<T>* GetTail();
	inline unsigned int GetIndex();

private:
	LinkedList<T>* head;
	LinkedList<T> *next;
	unsigned int index;
	LinkedList(LinkedList<T>* _head, unsigned int _index);
};


int main()
{
	LinkedList<std::string> list("Test1");
	LinkedList<std::string> listCopy;
	LinkedList<int>* sortedList;
	list.Insert("Test2");
	list.Insert("Test3");
	list.Insert("Test4");
	std::cout << list.GetAtIndex(1)->element << std::endl;
	std::cout << list.GetIndex() << std::endl;
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

	listCopy = *list.Reverse();

	std::cout << std::endl;
	listCopy.PrintAll();

	

	sortedList = new LinkedList<int>(2);
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


	getchar();
    return 0;
}

template<class T>
LinkedList<T>::LinkedList()
{
	next = NULL;
	head = NULL;
}

template<class T>
LinkedList<T>::LinkedList(const T & _head)
{
	element = _head;
	next = NULL;
	head = this;
	index = 0;
}

template<class T>
int LinkedList<T>::Count()
{
	int count = 0;
	LinkedList<T>* ref = head;
	do
	{
		ref->index = count++;
		ref = ref->next;
	} while (ref != NULL);
	return count;
}

template<class T>
void LinkedList<T>::Insert(const T & newElement)
{
	LinkedList<T>* ref = this;
	unsigned int count = 0;
	while (ref->next != NULL)
	{
		++count;
		ref = ref->next;
	}
	ref->next = new LinkedList<T>(head,count);
	ref->next->element = newElement;
}

template<class T>
void LinkedList<T>::Remove(const unsigned int & _index)
{
	LinkedList* ref = head, *severed = NULL;
	for (unsigned int i = 0; i < _index - 1; ++i)
	{
		if(ref->next != NULL)
			ref = ref->next;
		else return;
	}
	severed = ref->next->next;
	delete ref->next;
	ref->next = severed;
	head->Count();
}

template<class T>
void LinkedList<T>::Remove(const T & elementToRemove)
{
	LinkedList<T>* deletionVar = this->Search(elementToRemove);
	LinkedList<T>* ref = this->GetAtIndex(deletionVar->GetIndex() - 1);
	ref->next = deletionVar->next;
	delete deletionVar;
	head->Count();
}

template<class T>
void LinkedList<T>::RemoveAll(const T & elementToRemove)
{
	while (this->Contains(elementToRemove))
	{
		this->Remove(elementToRemove);
	}
}

template<class T>
LinkedList<T>* LinkedList<T>::GetAtIndex(const unsigned int & _index)
{
	LinkedList<T>* ref = head;
	for (unsigned int i = 0; i < _index; ++i)
	{
		ref = ref->next;
	}
	return ref;
}

template<class T>
bool LinkedList<T>::Contains(const T & _element)
{
	return (this->Search(_element) != NULL) ? true : false;
}

template<class T>
LinkedList<T>* LinkedList<T>::Search(const T & _element)
{
	LinkedList<T>* ref = head;
	do
	{
		if (ref->element == _element)
			return ref;
		ref = ref->next;
	} while (ref != NULL);
	return NULL;
}

template<class T>
void LinkedList<T>::InsertSorted(const T & newElement, bool lessVal)
{
	LinkedList<T>* ref = head, *refCopy = NULL;
	if (lessVal)
	{
		while (ref != NULL && ref->element >= newElement)
		{
			ref = ref->next;
		}
	}
	else
	{
		while (ref != NULL && ref->element <= newElement)
		{
			ref = ref->next;
		}
	}

	if (ref == head)
	{
		T headVal = head->element;
		ref = head->next;
		this->head->element = newElement;
		this->head->next = new LinkedList<T>(this->head, 1);
		this->head->next->element = headVal;
		this->head->next->next = ref;
	}
	else
	{
		if (ref == NULL)
		{
			this->head->Insert(newElement);
			this->Count();
			return;
		}
		refCopy = this->GetAtIndex(ref->GetIndex() - 1)->next = new LinkedList(head, ref->GetIndex());
		refCopy->element = newElement;
		refCopy->next = ref;
	}
	this->Count();
}

template<class T>
void LinkedList<T>::InsertElements(const T * elements, unsigned int size)
{
	for (unsigned int i = 0; i < size; ++i)
		this->Insert(elements[i]);
}

template<class T>
LinkedList<T>* LinkedList<T>::Reverse()
{
	LinkedList<T>* ref = this->GetTail(), *tailRef = ref;
	unsigned int tailIndex = tailRef->GetIndex();
	ref->head = ref;
	for (unsigned int i = tailIndex ; i > 0 ; --i)
	{
		ref->head = tailRef;
		ref->next = this->GetAtIndex(i-1);
		ref = ref->next;
	}
	ref->head = tailRef;
	ref->next = NULL;
 	ref->Count();
	ref = ref->head;
	return ref;
}

template<class T>
void LinkedList<T>::PrintAll()
{
	LinkedList<T>* ref = head;
	while (ref != NULL)
	{
		std::cout << ref->element << std::endl;
		ref = ref->next;
	}
}

template<class T>
LinkedList<T>* LinkedList<T>::GetTail()
{
	LinkedList<T>* ref = head;
	while (ref->next != NULL)
		ref = ref->next;
	return ref;
}

template<class T>
unsigned int LinkedList<T>::GetIndex()
{
	return index;
}

template<class T>
LinkedList<T>::LinkedList(LinkedList<T>* _head, unsigned int _index)
{
	next = NULL;
	head = _head;
	index = _index;
}
