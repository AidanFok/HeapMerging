#include "leftist.h"
leftist_heap::leftist_heap(std::vector<int>& conts){
	int size = conts.size(), min = 0, temp;
	this->left = NULL;
	this->right = NULL;
	for (int index = 0; index < size; index++){
		if (conts[index] < conts[min])min = index;
	}
	temp = conts[0];
	conts[0] = conts[min];
	conts[min] = temp;
	this->value = conts[0];
	for (int index = 1; index < size; index++){
		this->merge(new leftist_heap(conts[index]));
	}
}
leftist_heap* leftist_heap_merge(leftist_heap* h1, leftist_heap* h2){
	if (h1 == NULL){
		return h2;
	}
	else if (h2 == NULL){
		return h1;
	}
	else if (h1->value < h2->value){
		return leftist_heap_merge1(h1, h2);
	}
	return leftist_heap_merge1(h2, h1);
}
leftist_heap* leftist_heap_merge1(leftist_heap* smaller, leftist_heap* larger){
	if (smaller->left == NULL){
		smaller->left = larger;
	}
	else{
		smaller->right = leftist_heap_merge(smaller->right, larger);
		if (smaller->left->npl < smaller->right->npl){
			smaller->swap_children();
		}
		smaller->npl = smaller->right->npl + 1;
	}
	return smaller;
}
void leftist_heap::swap_children(){
	leftist_heap* temp = this->left;
	this->left = this->right;
	this->right = temp;
}
leftist_heap* leftist_heap::merge(heap* addition){
	return leftist_heap_merge(this, dynamic_cast<leftist_heap*>(addition));
}