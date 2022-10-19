#pragma once
#include "utility.h"
#include "DoubleNode.h"

// 双向链表
template<typename T>
class DoubleLinkList {
protected:
	dNode<T>* head; // 头节点
	dNode<T>* now; // 当前指针
	int l_size; // 大小
	void getPos(int idx); // 通过下标调整当前指针位置
public:
	typedef dNode<T>* node;
	DoubleLinkList();
	DoubleLinkList(T *arr, int n);
	~DoubleLinkList();
	int insert(int idx, T entry); // 增
	int remove(int idx); // 删
	int set(int idx, T entry); // 改
	int get(int idx, T &res); // 获取
	dNode<T>* search(T entry); // 查
	int size(); // 获取大小
	void print(); // 打印
};

template<typename T>
inline void DoubleLinkList<T>::getPos(int idx)
{
	now = head;
	for (int i = 0; i < idx; i ++) {
		now = now->nxt;
	}
}

template<typename T>
inline DoubleLinkList<T>::DoubleLinkList()
{
	head = new dNode<T>(0);
	now = head;
	l_size = 0;
}

template<typename T>
inline DoubleLinkList<T>::DoubleLinkList(T* arr, int n)
{
	head = new dNode<T>(0);
	now = head;
	l_size = n;
	for (int i = 0; i < n; i ++) {
		dNode<T>* tmp = new dNode<T>(arr[i]);
		tmp->pre = now;
		now->nxt = tmp;
		now = tmp;
	}
}

template<typename T>
inline DoubleLinkList<T>::~DoubleLinkList()
{
	now = head;
	while (now != NULL) {
		dNode<T>* tmp = now;
		now = now->nxt;
		delete tmp;
	}
}

template<typename T>
inline int DoubleLinkList<T>::insert(int idx, T entry)
{
	if (idx > l_size || idx < 0) return INDEX_OUT_OF_BOUND;
	getPos(idx);
	dNode<T>* tmp = new dNode<T>(entry);
	tmp->nxt = now->nxt;
	now->nxt = tmp;
	tmp->pre = now;
	tmp->nxt->pre = tmp;
	l_size += 1;
	return SUCCESS;
}

template<typename T>
inline int DoubleLinkList<T>::remove(int idx)
{
	if (idx >= l_size || idx < 0) return INDEX_OUT_OF_BOUND;
	getPos(idx);
	dNode<T>* tmp = now->nxt;
	now->nxt = tmp->nxt;
	if (now->nxt != NULL) {
		now->nxt->pre = now;
	}
	delete tmp;
	l_size -= 1;
	return SUCCESS;
}

template<typename T>
inline int DoubleLinkList<T>::set(int idx, T entry)
{
	if (idx >= l_size || idx < 0) return INDEX_OUT_OF_BOUND;
	getPos(idx);
	now = now->nxt;
	now->entry = entry;
	return SUCCESS;
}

template<typename T>
inline int DoubleLinkList<T>::get(int idx, T &res)
{
	if (idx >= l_size || idx < 0) return INDEX_OUT_OF_BOUND;
	getPos(idx);
	res = now->nxt->entry;
	return SUCCESS;
}

template<typename T>
inline dNode<T>* DoubleLinkList<T>::search(T entry)
{
	dNode<T>* p = head;
	while (p != NULL) {
		if (p->entry == entry) return p;
		p = p->nxt;
	}
	return NULL;
}

template<typename T>
inline int DoubleLinkList<T>::size()
{
	return l_size;
}

template<typename T>
inline void DoubleLinkList<T>::print()
{
	now = head->nxt;
	while (now != NULL) {
		cout << now->entry << " ";
		now = now->nxt;
	}
	cout << endl;
}
