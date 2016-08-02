#include "heap.h"
ordin_heap::ordin_heap(std::vector<int>& conts){
	int size = conts.size();
	this->conts.push_back(INT_MIN);
	this->size = size;
	for (int i = 0; i < size; i++){
		this->conts.push_back(conts[i]);
	}
	adjust(this);
}
void adjust(ordin_heap *h){
	for (int child=h->size/2; child > 0; child--){
		int sub, ss, parent_value = h->conts[child];
		for (sub = child, ss = MIN_CHILD(sub, h->conts); (ss<h->size) && h->conts[sub] > h->conts[ss]; sub = ss, ss= MIN_CHILD(sub, h->conts)){
			h->conts[sub] = h->conts[ss];
		}
		h->conts[sub] = parent_value;
	}
}
ordin_heap* ordin_heap_merge(ordin_heap* base, ordin_heap* addition){
	for (int index = 1; index <= addition->size; index++){
		base->conts.push_back(addition->conts[index]);
	}
	adjust(base);
	return base;
}
ordin_heap* ordin_heap::merge(heap* addtion){
	return ordin_heap_merge(this, dynamic_cast<ordin_heap*>(addtion));
}