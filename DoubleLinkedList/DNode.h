#pragma once
template<class T>
class DNode
{
public:
	T element;
	DNode* next;
	DNode* last;
	unsigned int index;
	DNode(T elem) : DNode(elem, 0, NULL, NULL) {}
	DNode(T elem, unsigned int _index, DNode<T>* _last, DNode<T>* _next)
	{
		element = elem;
		index = _index;
		last = _last;
		if(last != NULL)
			last->next = this;
		next = _next;
		if (next != NULL)
			next->last = this;
	}
	~DNode() {}
};

