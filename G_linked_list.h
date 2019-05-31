#ifndef __G_linked_list_h__
#define __G_linked_list_h__
#include<iostream>
template<class T> 
class G_node;
template<class T>
class G_linked_list{
	public:
		G_node<T>* first;	
		int size;
		inline G_linked_list(G_node<T>* first):size(1),first(first){}
		inline G_linked_list(){
			first = new G_node<T>();
			size =0;
		}
		void add(G_node<T>* n);
		bool add_to(std::string sup, G_node<T>*sub );
		bool del(std:: string name);
		void print();
		void print(G_node<T>* n);
		void del_list();
		void del_list(G_node<T>* n);
		G_node<T>* find(std::string name);
		G_node<T>* find(G_node<T>* n, std::string name);
};
#endif
