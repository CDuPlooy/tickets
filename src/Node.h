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
	Object *data;

public:
	Node(){
		next = NULL;
	}
	~Node(){

	}
	/*! Gets the next node.
	\return A node pointer.
	*/
	Node *getNext(){
		return next;
	}

	/*! Sets the next node.
	\param node: The node to set next to.
	*/
	void setNext(Node *node){
		next = node;
	}

	/*! Sets the data pointer of  node.
	\param node: The node to set next to.
	*/
	void set( Object *value ){/**< Sets the data pointer of the node.*/
		data = value;
	}
	
	/*! Gets the data pointer of  node.
	\return An object pointer.
	*/
	Object *get(){/**< Returns the data pointer of the node.*/
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
