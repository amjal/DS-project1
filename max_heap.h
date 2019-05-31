#ifndef __max_heap_h__
#define __max_heap_h__
#include<iostream>
#include<vector>
template<class T>
class max_heap{
	public:
		std::vector<T*>* data;
		max_heap();
		void add(T*);
		void correct(int index);
		void del();
};
#endif
