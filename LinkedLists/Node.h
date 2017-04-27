#pragma once
template<class T> class Node
{

public:
	Node() {
		next = NULL;
		index = 0;
	}
	Node(T elem, unsigned int _index) {
		element = elem;
		next = NULL;
		index = _index;
	}
	T element;
	Node* next;
	unsigned int index;
};