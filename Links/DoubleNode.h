#pragma once

// ˫��ڵ�
template<typename T>
struct dNode {
	T entry; // ����
	dNode* pre, * nxt; // ָ��ǰһ���ͺ�һ����ָ��
	dNode(T entry) {
		this->entry = entry;
		pre = NULL;
		nxt = NULL;
	}
};