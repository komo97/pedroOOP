#pragma once
template<class T> class DNode
{
public:
	DNode() {
		next = NULL;
		last = NULL;
		index = 0;
	}
	DNode(T elem, DNode* _last, unsigned int _index) {
		element = elem;
		next = NULL;
		index = _index;
		last = _last;
	}

	T element;
	DNode* next, *last;
	unsigned int index;
};

