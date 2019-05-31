#ifndef __order_h__
#define __order_h__
class service;
class order{
	public:
		int time;
		int urgency;
		service * serv;
		inline order(service* serv, int time, int urgency):serv(serv),time(time),urgency(urgency){}
		inline void print(){
			cout << serv->name << " " << urgency<< endl; 
		}
};
#endif
