#include<iostream>
#include "max_heap.h"
#include<vector>
using namespace std;
template<class T>
max_heap<T>::max_heap(){
	data = new vector<T*>();
}
template<class T>
void swap(vector<T*>* data, int el_index, int parent_index){
	T* temp = data->at(parent_index);
	data->at(parent_index) = data->at(el_index);
	data->at(el_index) = temp;
}
template<class T>
void max_heap<T>::add(T* element){
	data->push_back(element);
	int el_index = data->size()-1;
	int parent_index = (el_index-1)/2;
	while(el_index && data->at(parent_index)->urgency<data->at(el_index)->urgency){
		swap(data, el_index, parent_index);
		el_index = parent_index;
		parent_index = (el_index-1)/2;
	}
}
template<class T>
int compare(vector<T*>* data, int index1 , int index2){
	if(data->at(index1)->urgency > data->at(index2)->urgency)
		return index1;
	if(data->at(index1)->urgency < data->at(index2)->urgency)
		return index2;
	if(data->at(index1)->time < data->at(index2)->time)
		return index1;
	return index2;
}
template<class T>
void max_heap<T>::correct(int index){
	int compared_index = -1;
	if(index*2 +2 >= data->size() && index*2 + 1 < data->size())
		compared_index = index*2+1;
	else if(index*2 +2 < data->size())
		compared_index = compare(data , index*2+2, index*2 +1);
	if(compared_index == -1)
		return;
	if(compare(data, index , compared_index) == compared_index){
		swap(data, index, compared_index);
		correct(compared_index);
	}
}	
template<class T>
void max_heap<T>::del(){
	while(data->size()){
		data->at(0)->print();
		swap(data, 0, data->size()-1);
		data->pop_back();
		correct(0);
	}
}	
