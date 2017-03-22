#pragma once
#include <iostream>
template<class T>
class SeqList
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

