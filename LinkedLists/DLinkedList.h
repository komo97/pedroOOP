#pragma once
template<class T> class DLinkedList
{
public:
	DLinkedList() {
		head = new DNode<T>();

	}

	DLinkedList(const T& _element) {
		head = new DNode<T>(_element, 0);
	}

	DNode<T>* head;
public:
	T element;

	int Count() {
		int count = 0;
		DNode<T>* ref = head;
		do
		{
			ref->index = count++;
			ref = ref->next;
		} while (ref != NULL);
		return count;
	}

	void Insert(const T& newElement) {
		DNode<T>* ref = head;
		unsigned int count = 0;
		while (ref->next != NULL)
		{
			++count;
			ref = ref->next;
		}
		ref->next = new DNode<T>(newElement, count);
	}

	void Remove(const unsigned int& _index) {
		DNode<T>* ref = head, *severed = NULL;
		for (unsigned int i = 0; i < _index - 1; ++i)
		{
			if (ref->next != NULL)
				ref = ref->next;
			else return;
		}
		severed = ref->next->next;
		delete ref->next;
		ref->next = severed;
		this->Count();
	}

	void Remove(const T& elementToRemove) {
		DNode<T>* deletionVar = this->Search(elementToRemove);
		DNode<T>* ref = this->GetAtIndex(deletionVar->index - 1);
		ref->next = deletionVar->next;
		delete deletionVar;
		this->Count();
	}

	void RemoveAll(const T& elementToRemove) {
		while (this->Contains(elementToRemove))
		{
			this->Remove(elementToRemove);
		}
	}

	DNode<T>* GetAtIndex(const unsigned int& _index) {
		DNode<T>* ref = head;
		for (unsigned int i = 0; i < _index; ++i)
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
			head->element = newElement;
			head->next = new DNode<T>(headVal, 1);
			head->next->next = ref;
		}
		else
		{
			if (ref == NULL)
			{
				this->Insert(newElement);
				this->Count();
				return;
			}
			refCopy = this->GetAtIndex(ref->index - 1)->next = new DNode<T>(newElement, ref->index);
			refCopy->next = ref;
		}
		this->Count();
	}

	void InsertElements(const T* elements, unsigned int size) {
		for (unsigned int i = 0; i < size; ++i)
			this->Insert(elements[i]);
	}

	void Reverse() {
		DNode<T>* ref = this->GetTail(), *tailRef = ref;
		unsigned int tailIndex = tailRef->index;
		for (unsigned int i = tailIndex; i > 0; --i)
		{
			ref->next = this->GetAtIndex(i - 1);
			ref = ref->next;
		}
		head->next = NULL;
		head = tailRef;
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

	DNode<T>* GetTail() {
		DNode<T>* ref = head;
		while (ref->next != NULL)
			ref = ref->next;
		return ref;
	}

	~DLinkedList() {
		this->DeleteList();
	}
	void Clear()
	{
		DeleteList();
	}

private:
	void DeleteList() {
		DNode<T>* head = head, *ptr = NULL;
		while (head)
		{
			ptr = head;
			head = ptr->next;
			delete ptr;
		}
	}
};

