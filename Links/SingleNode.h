#pragma once

// 单向节点
template<typename T>
struct sNode {
	T entry; // 数据
	sNode* nxt; // 指向下一个的指针
	sNode(T entry) {
		this->entry = entry;
		nxt = NULL;
	}
};