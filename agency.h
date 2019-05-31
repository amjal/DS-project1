#ifndef __agency_h__
#define __agency_h__
#include "service.h"
#include "G_linked_list.h"
class agency{
	public:
		std::string name;
		G_linked_list<service>* services;
		max_heap<order>* orders;
		inline agency(string name, G_linked_list<service>* services):name(name), services(services){}
		agency(string name){
			this->name = name;
			services = new G_linked_list<service>();
			orders = new max_heap<order>();
		}
};
#endif
