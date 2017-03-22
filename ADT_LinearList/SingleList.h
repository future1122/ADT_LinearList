#pragma once
#include <iostream>
#include "LinearList.h"
template <class T> class SingleList;
template <class T>
class Node {
	T element;
	Node<T> *link;
	friend class SingleList<T>;
};
template <class T>
class SingleList :
	public LinearList<T>
{
public:
	SingleList() { first = NULL; n = 0; }
	~SingleList();
	bool IsEmpty() const;
	int Length() const;
	bool Find(int i, T & x) const;
	int Search(T x) const;
	bool Insert(int i, T x);
	bool Delete(int i);
	bool Update(int i, T x);
	void Output(std::ostream& out) const;
private:
	Node<T> *first;
};


