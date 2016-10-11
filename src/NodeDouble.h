//!  Subclass of Node used to implement double linked lists.

#ifndef NODEDOUBLE_H
#define NODEDOUBLE_H
#include "Node.h"
class NodeDouble : public Node{
public:
	/*! Gets the previous node.
	\return A node pointer.
	*/
	NodeDouble *getPrev(){
		return prev;
	}

	/*! Gets the next node.
	\return A node pointer.
	*/
	NodeDouble *getNext(){
		return next;
	}

	/*! Sets the previous node.
	\param node: The node to set previous to.
	*/
	void setPrev(NodeDouble *node){
		prev = node;
	}

	/*! Sets the next node.
	\param node: The node to set next to.
	*/
	void setNext(NodeDouble *node){
		next = node;
	}

private:
	NodeDouble *prev;
	NodeDouble *next;
};
#endif
