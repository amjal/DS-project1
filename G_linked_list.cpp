#include<iostream>
#include "G_linked_list.h"
#include "G_node.h"
using namespace std;
template<class T>
void G_linked_list<T>::add(G_node<T>* n){
	G_node<T>* modified = new G_node<T>();
	* modified = *n;
	modified->next = NULL;
	if(size ==0){
		first = modified;
		size ++;
		return;
	}
	G_node<T>* temp = first;
	while(temp->next) temp = temp->next;
	temp->next = modified;
	size++;
}
template<class T>
bool G_linked_list<T>::add_to(string sup, G_node<T>*sub){
	G_node<T>* sup_node = find(sup);
	if(sup_node == NULL) return false; // not found
	if(sup_node->data == NULL) sup_node = first;
	else if(sup_node->next && sup_node->next->data->name == sup)
		sup_node = sup_node->next;
	else sup_node = sup_node->dlink;
	if(sup_node->dlink){
		sup_node = sup_node->dlink;
		while(sup_node->next) sup_node = sup_node->next;
		sup_node->next = sub;
	}
	else
		sup_node->dlink = sub;	
	size ++;
	return true;
}
template<class T>
G_node<T>* G_linked_list<T>::find(G_node<T>*n, string name){
	if(n == NULL) return NULL;
	if(n->next && n->next->data->name == name) return n;
	if(n->dlink && n->dlink->data->name == name) return n;
	G_node<T>* n1 = find(n->next, name);
	G_node<T>* n2 = find(n->dlink, name);
	if(n2 != NULL) return n2;
	return n1;
}
template<class T>
G_node<T>* G_linked_list<T>::find(string name){
	if(size == 0) return NULL;
	if(first->data->name == name)
		return new G_node<T>();
	return find(first , name);
}
template<class T>
void G_linked_list<T>::del_list(G_node<T>* n){
	if(n == NULL) return;
	del_list(n->dlink);
	del_list(n->next);
	delete n;
}
template<class T>
void G_linked_list<T>::del_list(){
	del_list(first);
	delete this;
}
template<class T>
bool G_linked_list<T>::del(string name){
	G_node<T>* temp = find(name);
	if(temp == NULL) return false;
	if(temp ->data ==NULL) {
		temp= first->next;
		first = temp;
		size --;
		return true;
	}
	G_node<T>* target = temp->next;// we won't be deleting dlinks
	temp->next = target->next;
	size --;
	return true;
}	
template<class T>
void G_linked_list<T>::print(G_node<T>* n){
	if(n == NULL){
		cout << '}';
		return;
	}
	cout << n->data->name;
	if(n->dlink){
		cout << '{';
		print(n->dlink);
	}
	if(n->next) cout << ',';
	print(n->next);
}
template<class T>
void G_linked_list<T>::print(){
	cout <<'{';
	print(first);
	cout <<endl;
}

