#ifndef LEFTIST_H
#define LEFTIST_H
#include "heap.h"
#include<iostream>
class leftist_heap : public heap{
	friend leftist_heap* leftist_heap_merge(leftist_heap* h1, leftist_heap* h2);
	friend leftist_heap* leftist_heap_merge1(leftist_heap* smaller, leftist_heap* larger);
public:
	leftist_heap(std::vector<int>& conts);
	leftist_heap(int value) :left(NULL), right(NULL), value(value){}
	leftist_heap* merge(heap* addition);
	void swap_children();
private:
	leftist_heap *left;
	leftist_heap *right;
	int value;
	int npl;
};
#endif
