#include <time.h>
#include <iostream>
#include <vector>
#include "heap.h"
#include "leftist.h"
#include "skew.h"
#define size 10000
#define times 10
using namespace std;
int main(){
	size_t time_start, time_end, time_cost;
	vector<int> conts1, conts2;
	for (int i = 0; i < size; i++){
		conts1.push_back(2 * i);
	}for (int i = 0; i < size; i++){
		conts2.push_back(2 * i + 1);
	}
	heap *test_object1[times], *test_object2[times];
	//merge operation will bring irreversible effect, to test multi times, multi test objects should be constructed
	//change 'skew_heap' to other types or add other type constructions to test other types
	for (int time = 0; time < times; time++){
		test_object1[time] = new ordin_heap(conts1);
		test_object2[time] = new ordin_heap(conts2);
	}
	//one test example
	time_start = clock();
	for (int time = 0; time < times; time++){
		test_object1[time]->merge(test_object2[time]);
	}
	time_end = clock();
	time_cost = time_end - time_start;
	cout << size << " + " << size << " objects merged " << times << " times in " << ((double)time_cost) / CLK_TCK << " seconds(" << time_cost << " clicks in total)";
	//end of the test example
	system("pause");
}