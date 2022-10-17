#pragma once

template<typename T>
struct sNode {
	T entry;
	sNode* nxt;
	sNode(T entry) {
		this->entry = entry;
		nxt = NULL;
	}
};