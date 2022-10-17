#pragma once
#include "DoubleLinkList.h"

template<typename T>
class CirDoubleLinkList : public DoubleLinkList<T> {
public:
	CirDoubleLinkList();
	CirDoubleLinkList(T *arr, int n);
	~CirDoubleLinkList();
	dNode<T>* search(T entry);
	void print();
};

template<typename T>
inline CirDoubleLinkList<T>::CirDoubleLinkList()
{
}

template<typename T>
inline CirDoubleLinkList<T>::CirDoubleLinkList(T* arr, int n): DoubleLinkList<T>(arr, n)
{
	dNode<T>* p = this->head;
	while (p->nxt != NULL) p = p->nxt;
	p->nxt = this->head->nxt;
	this->head->nxt->pre = p;
}

template<typename T>
inline CirDoubleLinkList<T>::~CirDoubleLinkList()
{
	// ²ð»·³ÉÁ´
	this->head->nxt->pre->nxt = NULL;
}

template<typename T>
inline dNode<T>* CirDoubleLinkList<T>::search(T entry) {
	dNode<T>* p = this->head->nxt;
	if (p->entry == entry) return p;
	dNode<T>* q = p->nxt;
	while (q != p) {
		if (q->entry == entry) return q;
		q = q->nxt;
	}
	return NULL;
}

template<typename T>
inline void CirDoubleLinkList<T>::print()
{
	dNode<T>* p = this->head->nxt;
	for (int i = 0; i < this->l_size; i++) {
		cout << p->entry << " ";
		p = p->nxt;
	}
	cout << endl;
}
