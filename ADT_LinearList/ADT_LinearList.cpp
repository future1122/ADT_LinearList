// ADT_LinearList.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "SeqList.h"
#include "SingleList.h"
#include "Polynominal.h"
int main()
{
	SeqList<int> listA(20);
	SingleList<int> listB;
	for (int i = 0; i < 10; ++i) {
		listA.Insert(i-1, i);
	}
	for (int i = 0; i < 5; ++i) {
		listB.Insert(i - 1, i);
	}
	listA.Output(cout);
	listB.Output(cout);
	cout << "����ʽ" << endl;
	Polynominal p, q;
	cin >> p;
	cout << p;
	cin >> q;
	cout << q;
	p = p + q;
	cout << p;
    return 0;
}

