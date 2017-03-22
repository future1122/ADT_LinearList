#include "stdafx.h"
#include "Term.h"

Term::Term(int c, int e):coef(c),exr(e)
{
	link = NULL;
}

Term::Term(int c, int e, Term * nxt) : coef(c), exr(e)
{
	link = nxt;
}

Term * Term::InsertAfter(int c, int e)
{
	link = new Term(c, e, link);
	return link;
}

std::ostream & operator<<(std::ostream &out, const Term &val1)
{
	switch (val1.coef) {
	case 0:
		return out;
		break;
	case -1:
		out << "-";
		break;
	default:
		out << val1.coef;
		break;
	}
	switch(val1.exr) {
		case 0:
			break;
		case 1:
			out << "X";
			break;
		default:
			out << "X^" << val1.exr;
			break;
	}
	return out;
	// TODO: 在此处插入 return 语句
}
