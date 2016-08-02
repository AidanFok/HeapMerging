#ifndef SKEW_H
#define SKEW_H
#include "heap.h"
#include<iostream>
class skew_heap : public heap{
	friend skew_heap* skew_heap_merge(skew_heap* h1, skew_heap* h2);
	friend skew_heap* skew_heap_merge1(skew_heap* smaller, skew_heap* larger);;
public:
	skew_heap* merge(heap* addition);
	skew_heap(std::vector<int>& conts);
	skew_heap(int value) :value(value), left(NULL), right(NULL){}
private:
	skew_heap *left;
	skew_heap *right;
	int value;
};
skew_heap* skew_heap_merge(skew_heap* h1, skew_heap* h2);
skew_heap* skew_heap_merge1(skew_heap* smaller, skew_heap* larger);;
#endif
