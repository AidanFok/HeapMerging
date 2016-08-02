#include "skew.h"
skew_heap* skew_heap_merge(skew_heap* h1, skew_heap* h2){
	if (h1 == NULL)return h2;
	if (h2 == NULL)return h1;
	if (h1->value > h2->value){
		return skew_heap_merge1(h2, h1);
	}
	return skew_heap_merge1(h1, h2);
}
skew_heap* skew_heap_merge1(skew_heap* smaller, skew_heap* larger){
	skew_heap* temp = smaller->right;
	smaller->right = smaller->left;
	smaller->left = skew_heap_merge(temp, larger);
	return smaller;
}
skew_heap* skew_heap::merge(heap* addition){
	return skew_heap_merge(this, dynamic_cast<skew_heap*>(addition));
}
skew_heap::skew_heap(std::vector<int>& conts){
	int size = conts.size(), min = 0, temp;
	this->left = NULL;
	this->right = NULL;
	for (int index = 0; index < size; index++){
		if (conts[index] < conts[min])min = index;
	}
	temp = conts[0];
	conts[0] = conts[min];
	conts[min] = conts[0];
	this->value = temp;
	for (int index = 1; index < size; index++){
		this->merge(new skew_heap(conts[index]));
	}
}