#pragma once
#ifndef _TERM_H_
#define _TERM_H_


#include<iostream>
class Term
{
public:
	Term(int c,int e);
	Term(int c, int e, Term *nxt);
	Term *InsertAfter(int c, int e);


private:
	int coef;
	int exr;
	Term *link;
	friend std::ostream & operator<<(std::ostream &, const Term &);
	friend class Polynominal;
};
#endif // !_TERM_H_
