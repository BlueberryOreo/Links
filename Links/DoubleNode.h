#pragma once

// 双向节点
template<typename T>
struct dNode {
	T entry; // 数据
	dNode* pre, * nxt; // 指向前一个和后一个的指针
	dNode(T entry) {
		this->entry = entry;
		pre = NULL;
		nxt = NULL;
	}
};