#pragma once
#ifndef _POLYNOMINAL_H_
#define _POLYNOMINAL_H_
#include "Term.h"
using namespace std;
class Polynominal
{
public:
	Polynominal();
	~Polynominal();
	void AddTerms(istream& in);
	void Output(ostream& out)const;
	void PolyAdd(Polynominal &r);
private:
	Term* theList = NULL;
	friend ostream & operator<<(ostream &out, const Polynominal&val1);
	friend istream& operator >> (istream &is, Polynominal &val1);
	friend Polynominal& operator+(Polynominal&val1, Polynominal&val2);
};
#endif // !_POLYNOMINAL_H_