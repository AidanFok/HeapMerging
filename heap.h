#ifndef HEAP_H
#define HEAP_H
#include <vector>
#ifndef INT_MIN
#define INT_MIN 0xffffffff
#endif
#define MIN_CHILD(parent, h) (h[(parent)*2+1]?((h[(parent)*2+1]>h[(parent)*2])?((parent)*2):((parent)*2+1)):(parent)*2)
class heap{
public:
	virtual heap* merge(heap* addition)=0;
};
class ordin_heap : public heap{
	friend ordin_heap* ordin_heap_merge(ordin_heap* base, ordin_heap* addition);
	friend void adjust(ordin_heap *h);
public:
	ordin_heap(std::vector<int>& conts);
	ordin_heap* merge(heap* addition);
private:
	int size;
	std::vector<int> conts;
};
void adjust(ordin_heap* h);
ordin_heap* ordin_heap_merge(ordin_heap* base, ordin_heap* addition);
#endif