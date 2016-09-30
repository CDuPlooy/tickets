//!  Subclass of Node used to implement double linked lists.

#ifndef NODEDOUBLE_H
#define NODEDOUBLE_H
#include "Node.h"
class NodeDouble : public Node{
public:
	NodeDouble *getPrev(){
		return prev;
	}
	NodeDouble *getNext(){
		return next;
	}
	void setPrev(NodeDouble *node){
		prev = node;
	}
	void setNext(NodeDouble *node){
		next = node;
	}

private:
	NodeDouble *prev;
	NodeDouble *next;
};
#endif
