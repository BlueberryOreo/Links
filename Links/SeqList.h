#pragma once
#include "utility.h"

// ˳���
template<typename T>
class SeqList {
protected:
	T* list; // ˳�������
	int head; // ͷָ��
	int memory; // ˳�����ռ�ڴ�
	int size; // ˳����С
	int getIdx(T *pos); // ͨ��ָ���ȡ�±�
public:
	SeqList();
	SeqList(T *arr, int n);
	~SeqList();
	int insert(int idx, T entry); // ��
	int remove(int idx); // ɾ
	int set(int idx, T entry); // ��
	int get(int idx, T &res); // ȡ
	T* search(T entry); // ��
	void print(); // ��ӡ
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
	// �±��0��ʼ
	// ԭ����idx��λ����entryռ�ݣ���ԭ����idx��λ�õ�Ԫ�ؿ�ʼȫ�������һ��
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