#include "G_node.h"
using namespace std;
template<class T>
G_node<T> :: ~G_node(){
	delete data;
}

