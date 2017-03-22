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

template<class T>
inline SingleList<T>::~SingleList()
{
	while (first) {
		Node<T> *p;
		p = first->link;
		delete first;
		first = p;;
	}
}

template<class T>
inline bool SingleList<T>::IsEmpty() const
{
	return n == 0;
}

template<class T>
inline int SingleList<T>::Length() const
{
	return n;
}

template<class T>
inline bool SingleList<T>::Find(int i, T & x) const
{
	if (i<0 || i>n - 1) {
		std::cout << "out of bounds" << endl;
		return false;
	}
	Node<T> *p = first;
	for (int j = 0; j < i; ++j) {
		p = p->link;
	}
	x = p->element;
	return true;
}

template<class T>
inline int SingleList<T>::Search(T x) const
{
	Node<T> *p = first;
	for (int j = 0; p; ++j) {
		if (p->element == x) return j;
		p = p->link;
	}
	return -1;
}

template<class T>
inline bool SingleList<T>::Insert(int i, T x)
{
	if (i<-1 || i>n - 1) {
		std::cout << "out of bounds" << endl;
		return false;
	}
	Node<T> *q = new Node<T>;
	q->element = x;
	Node<T> *p = first;
	for (int j = 0; j < i; ++j) {
		p = p->link;
	}
	if (i == -1) {
		q-> link= first;
		first = q;
	}
	else {
		q->link = p->link;
		p->link = q;
	}
	n++;
	return true;
}

template<class T>
bool SingleList<T>::Delete(int i)
{
	if (n == 0) {
		std::cout << "UnderFlow" << endl;
		return false;
	}
	if (i<0 || i>n - 1) {
		std::cout << "out of bounds" << endl;
		return false;
	}

	Node<T> *p = first, *q = first;
	for (int j = 0; j < i - 1; j++)p = p->link;
	if (i == 0) {
		first = first->link;
	}
	else {
		q = p->link;
		p->link = q->link;
	}
	delete q;
	n--;
	return true;
}

template<class T>
bool SingleList<T>::Update(int i, T x)
{
	if (i<0 || i>n - 1) {
		std::cout << "out of bounds" << endl;
		return false;
	}
	Node<T> *p = first;
	for (int j = 0; j < i; j++)p = p->link;
	p->element = x;
	return true;
}

template<class T>
void SingleList<T>::Output(std::ostream & out) const
{
	Node<T> *p = first;
	while (p) {
		out << p->element << " ";
		p = p->link;
	}
	out << endl;
}

