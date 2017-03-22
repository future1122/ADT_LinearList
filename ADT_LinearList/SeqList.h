#pragma once
#include <iostream>
#include "LinearList.h"
using namespace std;
template<class T>
class SeqList
	:public LinearList<T>
{
public:
	SeqList(int );
	~SeqList() { delete[] elements; };
	bool IsEmpty() const;
	int Length() const;
	bool Find(int i, T & x) const;
	int Search(T x) const;
	bool Insert(int i, T x);
	bool Delete(int i);
	bool Update(int i, T x);
	void Output(std::ostream& out) const;
private:
	int maxLength;
	T *elements;
protected:
	int n;
};
template<class T>
SeqList<T>::SeqList(int mSize)
{
	maxLength = mSize;
	elements = new T[maxLength];
	n = 0;
}
template<class T>
bool SeqList<T>::IsEmpty() const
{
	return n == 0;
}

template<class T>
int SeqList<T>::Length() const
{
	return n;
}

template<class T>
bool SeqList<T>::Find(int i, T & x) const
{
	if (i < 0 || i > n - 1) {
		cout << "out of bounds" << endl;
		return false;
	}
	x = elements[i];
	return true;
}

template<class T>
int SeqList<T>::Search(T x) const
{
	for (int i = 0; i < n; ++i)
	{
		if (x == elements[i])return i;
	}
	return -1;
}

template<class T>
bool SeqList<T>::Insert(int i, T x)
{
	if (i < -1 || i > n - 1) {
		cout << "out of bounds" << endl;
		return false; //越界检查
	}
	if (n == maxLength) {
		cout << "OverFlow" << endl;
		return false;
	}  //  判断线性表是否已经满。
	for (int j = n - 1; j > i; --j) {
		elements[j + 1] = elements[j];
	}
	elements[i + 1] = x;
	n++;
	return true;
}

template<class T>
bool SeqList<T>::Delete(int i)
{
	if (!n) {
		cout << "UnderFlow" << endl;
		return false;
	}// 判断线性表内容是否为0个 
	if (i < 0 || i > n - 1) {
		cout << "out of bounds" << endl;
		return false; //越界检查
	}
	for (int j = i + 1; j < n; j++) {
		elements[j - 1] = elements[j];
	}
	n--;
	return true;
}

template<class T>
bool SeqList<T>::Update(int i, T x)
{
	if (i < 0 || i > n - 1) {
		cout << "out of bounds" << endl;
		return false; //越界检查
	}
	elements[i] = x;
	return true;
}

template<class T>
void SeqList<T>::Output(std::ostream & out) const
{
	for (int j = 0; j < n; ++j) {
		out << elements[j] << " ";
	}
	out << endl;
}

