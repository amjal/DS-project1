#ifndef __service_h__
#define __service_h__
#include<iostream>
using namespace std;
class service{
	public:
		string name;
		string car_model;
		string client_des;
		string agency_des;
		double expenses;
		int agencies;
		inline service(string s1, string s2, string s3, string s4, double s5):agencies(0),name(s1),car_model(s2), client_des(s3), agency_des(s4), expenses(s5){}
		inline service():agencies(0),name("UKNOWN"),car_model("UKNOWN"), client_des("UKNOWN"), agency_des("UKNOWN"), expenses(0){
		}
		inline service(string s):agencies(0),name(s),car_model("UKNOWN"), client_des("UKNOWN"), agency_des("UKNOWN"), expenses(0){}	
};
#endif

