//!  Node class used to implement single, double and quadruple linked list.

#ifndef NODE_H
#define NODE_H
#include <cstddef>
#include "Object.h"
class Node : public Object{
protected:
		int compareTo(Object const &) const{
			return 1;
		}
private:
	Node *next;
	int data;

public:
	Node(){
		next = NULL;
	}
	~Node(){

	}
	Node *getNext(){
		return next;
	}
	void setNext(Node *node){
		next = node;
	}
	void set( int value ){
		data = value;
	}
	int get(){
		return data;
	}
	//So it can inheret from Object.
	bool isNull(void) const{
		return false;
	}

	int compare(Object const &) const{
		return 1;
	}

	void print(std::ostream &out = std::cout) const{
		out << "Node";
	}

	std::string getId() const{
		return "Node";
	}
};
#endif
