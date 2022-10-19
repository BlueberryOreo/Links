#pragma once
#include "utility.h"

// 顺序表
template<typename T>
class SeqList {
protected:
	T* list; // 顺序表数组
	int head; // 头指针
	int memory; // 顺序表所占内存
	int size; // 顺序表大小
	int getIdx(T *pos); // 通过指针获取下标
public:
	SeqList();
	SeqList(T *arr, int n);
	~SeqList();
	int insert(int idx, T entry); // 增
	int remove(int idx); // 删
	int set(int idx, T entry); // 改
	int get(int idx, T &res); // 取
	T* search(T entry); // 查
	void print(); // 打印
};

template<typename T>
inline int SeqList<T>::getIdx(T* pos)
{
	return pos - list;
}

template<typename T>
SeqList<T>::SeqList() {
	size = 1;
	memory = 1;
	list = new T[size];
	head = 0;
}

template<typename T>
SeqList<T>::SeqList(T *arr, int n) {
	size = n;
	memory = n;
	list = new T[size];
	head = 0;
	for (int i = 0; i < n; i ++) {
		list[i] = arr[i];
	}
}

template<typename T>
SeqList<T>::~SeqList() {
	delete[] list;
}

template<typename T>
int SeqList<T>::insert(int idx, T entry) {
	// 下标从0开始
	// 原来第idx号位置由entry占据，从原来第idx号位置的元素开始全部向后移一格
	if (idx > size || idx < 0) return INDEX_OUT_OF_BOUND;
	if (size == memory) {
		T* tmp = new T[2 * memory];
		memory *= 2;
		for (int i = 0; i < size; i ++) {
			tmp[i] = list[i];
		}
		delete[] list;
		list = tmp;
	}
	for (int i = size - 1; i >= idx; i --) {
		list[i + 1] = list[i];
	}
	list[idx] = entry;
	size += 1;
	return SUCCESS;
}

template<typename T>
int SeqList<T>::remove(int idx) {
	if (idx >= size || idx < 0) return INDEX_OUT_OF_BOUND;
	for (int i = idx; i < size; i ++) {
		list[i] = list[i + 1];
	}
	size -= 1;
	return SUCCESS;
}

template<typename T>
int SeqList<T>::set(int idx, T entry) {
	if (idx >= size || idx < 0) return INDEX_OUT_OF_BOUND;

	list[idx] = entry;

	return SUCCESS;
}

template<typename T>
int SeqList<T>::get(int idx, T &res) {
	if (idx >= size || idx < 0) return INDEX_OUT_OF_BOUND;
	res = list[idx];
	return SUCCESS;
}

template<typename T>
T* SeqList<T>::search(T entry) {
	for (int i = 0; i < size; i ++) {
		if (entry == list[i]) return &list[i];
	}
	return NULL;
}

template<typename T>
void SeqList<T>::print() {
	for (int i = 0; i < size; i ++) {
		cout << list[i] << " ";
	}
	cout << endl;
}