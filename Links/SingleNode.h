#pragma once

// ����ڵ�
template<typename T>
struct sNode {
	T entry; // ����
	sNode* nxt; // ָ����һ����ָ��
	sNode(T entry) {
		this->entry = entry;
		nxt = NULL;
	}
};