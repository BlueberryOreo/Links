#pragma once
#include "utility.h"
#include "SingleNode.h"

template<typename T>
class SingleLinkList {
protected:
	sNode<T>* head;
	int l_size;
	sNode<T>* getPos(int idx);
public:
	typedef sNode<T>* node; // ÷∏’Î
	SingleLinkList();
	SingleLinkList(T *arr, int n);
	~SingleLinkList();
	int insert(int idx, T entry);
	int remove(int idx);
	int set(int idx, T entry);
	int get(int idx, T &res);
	sNode<T>* search(T entry);
	int size();
	void print();
};

template<typename T>
inline sNode<T>* SingleLinkList<T>::getPos(int idx)
{
	sNode<T>* p = head;
	for (int i = 0; i < idx; i ++) {
		p = p->nxt;
	}
	return p;
}

template<typename T>
inline SingleLinkList<T>::SingleLinkList() {
	head = new sNode<T>(0);
	l_size = 0;
}

template<typename T>
inline SingleLinkList<T>::SingleLinkList(T *arr, int n) {
	l_size = n;
	head = new sNode<T>(0);
	sNode<T>* p = head;
	for (int i = 0; i < n; i ++) {
		sNode<T>* tmp = new sNode<T>(arr[i]);
		p->nxt = tmp;
		p = p->nxt;
	}
}

template<typename T>
inline SingleLinkList<T>::~SingleLinkList() {
	sNode<T>* p = head;
	while (p != NULL) {
		sNode<T>* tmp = p;
		p = p->nxt;
		delete tmp;
	}
}

template<typename T>
inline int SingleLinkList<T>::insert(int idx, T entry)
{
	if (idx > l_size || idx < 0) return INDEX_OUT_OF_BOUND;
	sNode<T>* p = getPos(idx);
	sNode<T>* tmp = new sNode<T>(entry);
	tmp->nxt = p->nxt;
	p->nxt = tmp;
	l_size += 1;
	return SUCCESS;
}

template<typename T>
inline int SingleLinkList<T>::remove(int idx)
{
	if (idx >= l_size || idx < 0) return INDEX_OUT_OF_BOUND;
	sNode<T>* p = getPos(idx);
	sNode<T>* tmp = p->nxt;
	p->nxt = tmp->nxt;
	delete tmp;
	l_size -= 1;
	return SUCCESS;
}

template<typename T>
inline int SingleLinkList<T>::set(int idx, T entry)
{
	if (idx >= l_size || idx < 0) return INDEX_OUT_OF_BOUND;
	sNode<T>* p = getPos(idx);
	p->nxt->entry = entry;
	return SUCCESS;
}

template<typename T>
inline int SingleLinkList<T>::get(int idx, T &res)
{
	if (idx >= l_size || idx < 0) return INDEX_OUT_OF_BOUND;
	res = getPos(idx)->nxt->entry;
	return SUCCESS;
}

template<typename T>
inline sNode<T>* SingleLinkList<T>::search(T entry)
{
	sNode<T>* p = head->nxt;
	while (p != NULL) {
		if (p->entry == entry) return p;
		p = p->nxt;
	}
	return NULL;
}

template<typename T>
inline int SingleLinkList<T>::size()
{
	return l_size;
}

template<typename T>
inline void SingleLinkList<T>::print()
{
	sNode<T>* p = head->nxt;
	while (p != NULL) {
		cout << p->entry << " ";
		p = p->nxt;
	}
	cout << endl;
}

