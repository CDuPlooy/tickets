
#include "Object.h"
#include "ListAsDLL.h"


ListAsDLL::~ListAsDLL(){

}
ListAsDLL::ListAsDLL(){
      head = NULL;
}

bool ListAsDLL::isNull(void) const{
      return false;
}
int ListAsDLL::compare(Object const &) const{
      return 1;
}
void ListAsDLL::print(std::ostream &out) const{
      out << "Marker:Unsure";
}
std::string ListAsDLL::getId() const{
      return "ListAsSLL";
}

int ListAsDLL::compareTo(Object const &) const{
      return 1;
}


void ListAsDLL::add( Object *value ){
	NodeDouble *node = new NodeDouble();
	//node->set(value);
	node->setNext(NULL);
	node->setPrev(NULL);

	if( !head ){
		head = node;
		return;
		}

	NodeDouble *current = head;
	while( current->getNext() )
		current = current->getNext();
	current->setNext(node);
	node->setPrev(current);
	node->setNext(NULL);

}

void ListAsDLL::previous(){

}

void ListAsDLL::next(){

}

void ListAsDLL::push_back(Object *object) {

}

void ListAsDLL::pop_back(){

}

Object *ListAsDLL::at(size_t i){
	return NULL;
}

void ListAsDLL::dump(){
	if(head == NULL)
		return;

	NodeDouble*temp = head;
	while( temp ){
		std::cout << "Node : " << temp->get() << std::endl;
		std::cout << "\tNext: " << temp->getNext() << std::endl;
		std::cout << "\tPrev: " << temp->getPrev() << std::endl;


		temp = temp->getNext();
	}
}

void ListAsDLL::remove(int value){
	if(head == NULL)
		return;
	if(head->getNext() == NULL){
		if(head->get() == value)
			delete head;
		head = NULL;
	}
	bool found = false;
	NodeDouble *prevl = head;
	NodeDouble *temp = head;
	while( temp ){
		if( value == temp->get() ){
			found = true;
			break;
		}
		prevl = temp;
		temp = temp->getNext();
		}

	if(found){
		if(temp->getNext() == NULL){
			delete temp;
			prevl->setNext(NULL);
			return;
		}
		else if(temp == head){
			if( temp->getNext() != NULL )
				head = (NodeDouble *)temp->getNext();
			else
				head = NULL;
			delete temp;
			return;
		}

		prevl->setNext(temp->getNext());
		temp->setPrev(prevl);
		delete temp;
		return;
	}
}

//TODO: Properly implement the linked list for ListAsDLL and ListAsSLL. As A note to myself , the push_back , pop_back and at functions should be overloaded in all subclasses of List so that all of them can work with Objects.
//TODO: Having one at function doesn't make sense. A FixedArray isn't indexed the same way a linked list is. Have at(size_t) for lists and at(size_t , size_t) for the matrixes.
