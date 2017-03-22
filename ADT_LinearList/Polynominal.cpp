#include "stdafx.h"
#include "Polynominal.h"


Polynominal::Polynominal()
{
	theList = new Term(0, -1);
	theList->link = theList;
}


Polynominal::~Polynominal()
{
	Term *p = theList-> link;
	while (p != theList) {
		theList->link = p->link;
		delete p;
		p = theList->link;
	}
	delete theList;
}

void Polynominal::AddTerms(std::istream & in) //按降幂输入各项，构成单循环列表。
{
	Term * q = theList;
	int c, e;
	while (true) {
		std::cout << "Input a term(coef,exr):\n" << std::endl;
		std::cin >> c >> e;
		if (e < 0)break;
		q = q->InsertAfter(c, e);
	}
}

void Polynominal::Output(std::ostream & out) const
{
	int first = 1;
	Term *p = theList->link;
	while (p != theList) {
		if (!first && (p->coef > 0)) {
			std::cout << "+";
		}
		first = 0;
		out << *p;
		p = p->link;
	}
	std::cout << "\n" << std::endl;
}

void Polynominal::PolyAdd(Polynominal & r)
{
	Term* q, *q1 = theList, *p;
	p = r.theList->link;
	q = q1->link;
	while (p->exr >= 0) {
		while (p->exr < q->exr) {
			q1 = q;
			q = q->link;
		}
		if (q->exr == p->exr)
		{
			q->coef += p->coef;
			if (q->coef == 0) {
				q1->link = q->link;
				delete q;
				q = q1->link;
			}
			else {
				q1 = q;
				q = q->link;
			}
		}
		else {
			q1 = q1->InsertAfter(p->coef, p->exr);
		}
		p = p->link;
	}
}

std::ostream & operator<<(std::ostream &out, const Polynominal &val1)
{
	val1.Output(out);
	return out;
	// TODO: 在此处插入 return 语句
}

std::istream & operator >> (std::istream & in, Polynominal &val1)
{
	val1.AddTerms(in);
	return in;
	// TODO: 在此处插入 return 语句
}

Polynominal & operator+(Polynominal &val1, Polynominal &val2)
{
	val1.PolyAdd(val2);
	return val1;
	// TODO: 在此处插入 return 语句
}
