#pragma once
#include "DoubleLinkList.h"

// 循环双链表
template<typename T>
class CirDoubleLinkList : public DoubleLinkList<T> {
public:
	CirDoubleLinkList();
	CirDoubleLinkList(T *arr, int n);
	~CirDoubleLinkList();
	dNode<T>* search(T entry); // 重写查找方法
	void print(); // 重写打印方法
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
	// 拆环成链
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
