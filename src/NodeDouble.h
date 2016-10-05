//!  Subclass of Node used to implement double linked lists.

#ifndef NODEDOUBLE_H
#define NODEDOUBLE_H
#include "Node.h"
class NodeDouble : public Node{
public:
	NodeDouble *getPrev(){/**< Returns the previous pointer of the node.*/
		return prev;
	}
	NodeDouble *getNext(){
		return next;
	}
	void setPrev(NodeDouble *node){/**< Sets the previous pointer of the node.*/
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
