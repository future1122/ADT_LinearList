#pragma once
#ifndef _LINEARLIST_H_
#define _LINEARLIST_H_


#include <iostream>
#include <ostream>
//线性表类
template <class T>
class LinearList
{
public:
	virtual bool IsEmpty() const = 0;
	virtual int Length() const = 0;
	virtual bool Find(int i, T & x) const = 0;
	virtual int Search(T x) const = 0;
	virtual bool Insert(int i, T x) = 0;
	virtual bool Delete(int i) = 0;
	virtual bool Update(int i, T x) = 0;
	virtual void Output(std::ostream& out) const = 0;
protected:
	int n;                           //线性表的长度
};
#endif // !_LINEARLIST_H_