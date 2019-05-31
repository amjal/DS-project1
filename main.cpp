#include<iostream>
#include "G_linked_list.h"
#include "G_node.h"
#include "service.h"
#include "G_linked_list.h"
#include "G_linked_list.cpp"
#include "G_node.cpp"
#include "max_heap.h"
#include "order.h"
#include "max_heap.cpp"
#include "agency.h"
#include<string>
using namespace std;
G_linked_list<service>* main_service_list = new G_linked_list<service>();
G_linked_list<agency>* agencies = new G_linked_list<agency>();
int order_order =0;
int process_command(string args[8]){
	if(args[0] == "exit") return 2;
	if(args[0] == "add" && args[1] == "service"){
		if(main_service_list->find(args[2]) != NULL) {
			cout << "*** SERVICE ALREADY EXISTS ***\n";
			return 0;
		}
		main_service_list-> add(new G_node<service>(new service(args[2])));
		return 0;
	}
	if(args[0] == "add" && args[1] == "subservice"){
		if(main_service_list->find(args[2]) != NULL) {
			cout << "*** SERVICE ALREADY EXISTS ***\n";
			return 0;
		}
		if(main_service_list-> add_to(args[4],new G_node<service>(new service(args[2]))));
		else cout << "*** SERVICE NOT FOUND ***\n";
		return 0;
	}
	if(args[0] == "add" && args[1] == "offer"){
		G_node<agency>* a = agencies->find(args[4]);
		G_node<service>* s = main_service_list->find(args[2]);
		if(a == NULL) {
			cout <<"*** AGENCY NOT FOUND ***\n";
			return 0;
		}
		if(a->data == NULL)
			a = agencies->first;
		else a = a->next;
		if(a->data->services->find(args[2]) != NULL) {
			cout << "*** SERVICE ALREADY EXISTS ***\n";
			return 0;
		}
		if(s == NULL){
			cout <<"*** SERVICE NOT FOUND ***\n";
			return 0;
		}
		if(s->data == NULL) s = main_service_list->first;
		else s = s->next;
		a->data->services->add(s);
		return 0;	
	}
	if(args[0] == "list" && args[1] == "agencies"){
		agencies->print();
		return 0;
	}
	if(args[0] == "list" && args[1] == "services" && args[2] == "from"){
		G_node<service>* s = main_service_list->find(args[3]);
		if(s == NULL){
			cout << "*** SERVICE NOT FOUND ***\n";
			return 0;
		}
		if(s -> data == NULL) s = main_service_list->first;
		else s = s->next;
		cout << '{';
		main_service_list->print(s->dlink);
		cout << endl;
		return 0;
	}
	if(args[0] == "list" && args[1] == "services" && args[2] == "by"){
		G_node<agency>* a = agencies->find(args[3]);
		if(a == NULL) {
			cout << "*** AGENCY NOT FOUND ***\n";
			return 0;
		}
		if(a->data == NULL) a = agencies->first;
		else a = a->next;
		a->data->services->print();
		return 0;
	}	
	if(args[0] == "list" && args[1] == "services"){
		main_service_list->print();
		return 0;
	}
	if(args[0] == "add" && args[1] == "agency"){
		agencies->add(new G_node<agency>(new agency(args[2])));
		return 0;
	}
	if(args[0] == "delete" && args[2] == "from"){
		G_node<agency>* a = agencies->find(args[3]);
		if(a == NULL){
			cout << "*** AGENCY NOT FOUND ***\n";
			return 0;
		}
		if(a->data == NULL) a= agencies->first;
		else a= a->next;
		services->del(args[1]);
		if(a->data->services->del(args[1]));
		else cout << "***SERVICE NOT FOUND ***\n";
		return 0;
	}
	if(args[0] == "order"){
		G_node<agency>* a = agencies->find(args[3]);
		if(a == NULL){
			cout <<"*** AGENCY NOT FOUND ***\n";
			return 0;
		}
		if(a->data == NULL)
			a = agencies->first;
		else a = a->next;
		G_node<service>* s = a->data->services->find(args[1]);
		if(s == NULL){
			cout << "*** SERVICE NOT SUPPORTED BY AGENCY***\n";
			return 0;
		}
		if(s->data == NULL)
			s = a->data->services->first;
		else if(s->next && s->next->data->name == args[1])
			s = s->next;
		else s = s->dlink;
		order* o = new order(s->data, order_order++, stoi(args[7]));
		a->data->orders->add(o);
		return 0;
	}
	if(args[0] == "list" && args[1] == "orders"){
		G_node<agency>* a = agencies->find(args[2]);
		if(a == NULL){
			cout <<"*** AGENCY NOT FOUND ***\n";
			return 0;
		}
		if(a->data == NULL)
			a = agencies->first;
		else a = a->next;
		a->data->orders->del();
		return 0;
	}
	return 1;
}
int main(){
	string in;
	int process_code;
	do{
		getline(cin, in);
		string args[8];
		int c=0;
		for(int i=0; i < in.length(); i++){
			if(in.at(i) == ' '){
				args[c++] = in.substr(0,i);
				in.erase(0,i+1);
				i = -1;
			}
		}
		args[c] = in;
		process_code = process_command(args);
		if(process_code == 1) cout<< "***INVALID COMMAND***\n";
	}while(process_code!= 2);// 2 is code for exit
	main_service_list->del_list();
	agencies->del_list();
	delete main_service_list;
	delete agencies;
	return 0;
}
