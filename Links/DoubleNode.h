#pragma once

template<typename T>
struct dNode {
	T entry;
	dNode* pre, * nxt;
	dNode(T entry) {
		this->entry = entry;
		pre = NULL;
		nxt = NULL;
	}
};