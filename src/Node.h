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
	Node *getNext(){/**< Returns the next node in the list.*/
		return next;
	}
	void setNext(Node *node){/**< Sets the next node in the list.*/
		next = node;
	}
	void set( Object *value ){/**< Sets the data pointer of the node.*/
		data = value;
	}
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
