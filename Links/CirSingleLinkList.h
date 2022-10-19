#pragma once
#include "utility.h"
#include "SingleLinkList.h"

// 循环单链表
template<typename T>
class CirSingleLinkList: public SingleLinkList<T> {
public:
	CirSingleLinkList();
	CirSingleLinkList(T* arr, int n);
	~CirSingleLinkList();
	sNode<T>* search(T entry); // 重写查找方法
	void print(); // 重写打印方法
};

template<typename T>
inline CirSingleLinkList<T>::CirSingleLinkList()
{
}

template<typename T>
inline CirSingleLinkList<T>::CirSingleLinkList(T* arr, int n): SingleLinkList<T>(arr, n)
{
	sNode<T>* p = this->head;
	while (p->nxt != NULL) p = p->nxt;
	p->nxt = this->head->nxt;
}

template<typename T>
inline CirSingleLinkList<T>::~CirSingleLinkList()
{
	// 拆环成链
	sNode<T>* p = this->head->nxt;
	this->head->nxt = p->nxt;
	p->nxt = NULL;
}

template<typename T>
inline sNode<T>* CirSingleLinkList<T>::search(T entry) {
	sNode<T>* p = this->head->nxt;
	if (p->entry == entry) return p;
	sNode<T>* q = p->nxt;
	while (q != p) {
		if (q->entry == entry) return q;
		q = q->nxt;
	}
	return NULL;
}

template<typename T>
inline void CirSingleLinkList<T>::print()
{
	sNode<T>* p = this->head->nxt;
	for (int i = 0; i < this->l_size; i ++) {
		cout << p->entry << " ";
		p = p->nxt;
	}
	cout << endl;
}
