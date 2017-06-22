#pragma once
template<class T>
class DNode
{
public:
	T element;
	DNode* next;
	DNode* last;
	unsigned int index;
	DNode(DNode<T>* const& cpy);
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

	DNode<T>* operator=(DNode<T>* const& cpy);
	static DNode<T>* ShallowCpy(DNode<T>* & dst, DNode<T>* const& src);
};

template<class T>
inline DNode<T>::DNode(DNode<T>* const & cpy) : DNode(cpy->element,cpy->index,cpy->last,cpy->next)
{
}

template<class T>
inline DNode <T>* DNode<T>::operator=(DNode<T>* const & cpy)
{
	this->element = cpy->element;
	this->index = cpy->index;
	this->last = cpy->last;
	this->next = cpy->next;
	return this;
}

template<class T>
inline DNode<T>* DNode<T>::ShallowCpy(DNode<T>*& dst, DNode<T>* const & src)
{
	dst = src;
	return dst;
}
