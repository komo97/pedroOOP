#pragma once
#include <iostream>
#include <string>
#include "DNode.h"

typedef struct Index {
	Index(unsigned int i) { index = i; }
	unsigned int index;
}Index;

template<class T>
class DLinkedList
{

public:
	DLinkedList() {
		head = NULL;
	}
	DLinkedList(const T& _element)
	{
		head = new DNode<T>(_element);
	}

public:
	unsigned int Count() {
		unsigned int count = 0;
		DNode<T>* ref = head;
		while (ref != NULL)
		{
			ref->index = count++;
			ref = ref->next;
		}
		return count;
	}

	void Insert(const T& newElement) {
		if (head == NULL)
		{
			head = new DNode<T>(newElement);
			return;
		}

		DNode<T>* ref = head;
		unsigned int count = 0;
		while (ref->next != NULL)
		{
			++count;
			ref = ref->next;
		}
		ref->next = new DNode<T>(newElement, count, ref, NULL);
	}

	void Remove(const Index& _index) {
		DNode<T>* ref = head, *severed = NULL;
		for (unsigned int i = 0; i < _index.index; ++i)
		{
			if (ref != NULL)
				ref = ref->next;
			else return;
		}
		if (ref->last != NULL)
		{
			ref->last->next = ref->next;
		}
		else head = NULL;
		if (ref->next != NULL)
			ref->next->last = ref->last;
		delete ref;
		this->Count();
	}

	void Remove(const T& elementToRemove) {
		DNode<T>* deletionVar = this->Search(elementToRemove);
		if (deletionVar->last != NULL)
		{
			deletionVar->last->next = deletionVar->next;
		}
		else head = NULL;
		if (deletionVar->next != NULL)
			deletionVar->next->last = deletionVar->last;
		delete deletionVar;
		this->Count();
	}

	void RemoveAll(const T& elementToRemove) {
		while (this->Contains(elementToRemove))
		{
			this->Remove(elementToRemove);
		}
	}

	DNode<T>* GetAtIndex(const Index& _index) {
		unsigned int c = this->Count(), index = _index.index;
		if (index >= c) index = c - 1;
		DNode<T>* ref = head;
		for (unsigned int i = 0; i < index && i < -1; ++i)
		{
			ref = ref->next;
		}
		return ref;
	}

	bool Contains(const T& _element) {
		return (this->Search(_element) != NULL) ? true : false;
	}

	DNode<T>* Search(const T& _element) {
		DNode<T>* ref = head;
		do
		{
			if (ref->element == _element)
				return ref;
			ref = ref->next;
		} while (ref != NULL);
		return NULL;
	}

	void InsertSorted(const T& newElement, bool lessVal) {
		DNode<T>* ref = head, *refCopy = NULL;
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
			this->head->next = new DNode<T>(headVal, 1, this->head, ref);
			this->head->next->element = headVal;
			this->head->next->next = ref;
		}
		else
		{
			if (ref == NULL)
			{
				this->Insert(newElement);
				this->Count();
				return;
			}
			ref = new DNode<T>(newElement, ref->index, ref->last, ref);
		}
		this->Count();
	}

	void InsertElements(const T* elements, unsigned int size) {
		for (unsigned int i = 0; i < size; ++i)
			this->Insert(elements[i]);
	}

	void Reverse() {
		DNode<T>* ref = this->GetTail(), *tailRef = ref;
		for (unsigned int i = tailRef->index; i >= 0 && i < -1; --i)
		{
			DNode<T>* refNext = ref->next;
			ref->next = ref->last;
			ref->last = refNext;
			ref = ref->next;
		}
		this->head->next = NULL;
		this->head = tailRef;
		this->Count();
	}

	void PrintAll() {
		DNode<T>* ref = head;
		while (ref != NULL)
		{
			std::cout << ref->element << std::endl;
			ref = ref->next;
		}
	}

	inline DNode<T>* GetHead() { return head; }

	DNode<T>* GetTail()
	{
		DNode<T>* ref = head;
		while (ref->next != NULL)
		{
			ref = ref->next;
		}
		return ref;
	}

	void Clear() {
		DNode<T>* ref = head;
		DNode<T>* delPtr = NULL;
		while (ref != NULL)
		{
			delPtr = ref->next;
			delete ref;
			ref = delPtr;
		}
	}
	~DLinkedList() {
		Clear();
	}

private:
	DNode<T>* head;
};
