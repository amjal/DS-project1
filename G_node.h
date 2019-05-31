#ifndef __G_node_h__
#define __G_node_h__
#include<iostream>
template<class T>
class G_node{
	public:
		G_node* next;
		G_node* dlink;
		T* data;
		inline G_node(T* data):data(data),next(NULL),dlink(NULL){}
		inline G_node():data(NULL),next(NULL),dlink(NULL){}
		~G_node();
};
#endif
