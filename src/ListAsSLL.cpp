
#include "Object.h"
#include "ListAsSLL.h"


ListAsSLL::~ListAsSLL(){
	head = NULL;
}
ListAsSLL::ListAsSLL(){

}

bool ListAsSLL::isNull(void) const{
      return false;
}
int ListAsSLL::compare(Object const &) const{
      return 1;
}
void ListAsSLL::print(std::ostream &out) const{
      out << "Marker:Unsure";
}
std::string ListAsSLL::getId() const{
      return "ListAsSLL";
}

int ListAsSLL::compareTo(Object const &) const{
      return 1;
}


void ListAsSLL::add( int value ){
	Node *node = new Node();
	node->set(value);
	node->setNext(NULL);

	if( !head ){
		head = node;
		return;
		}

	Node *temp = head;
	while( temp->getNext() )
		temp = temp->getNext();
	temp->setNext(node);

}

void ListAsSLL::dump(){
	if(head == NULL)
		return;

	Node *temp = head;
	while( temp ){
		std::cout << "Node : " << temp->get() << std::endl;
		temp = temp->getNext();
	}
}

void ListAsSLL::remove(int value){
	if(head == NULL)
		return;
	if(head->getNext() == NULL){
		if(head->get() == value)
			delete head;
		head = NULL;
	}
	bool found = false;
	Node *prev = head;
	Node *temp = head;
	while( temp ){
		if( value == temp->get() ){
			found = true;
			break;
		}
		prev = temp;
		temp = temp->getNext();
		}

	if(found){
		if(temp->getNext() == NULL){
			delete temp;
			prev->setNext(NULL);
			return;
		}
		else if(temp == head){
			if( temp->getNext() != NULL )
				head = temp->getNext();
			else
				head = NULL;
			delete temp;
			return;
		}

		prev->setNext(temp->getNext());
		delete temp;
		return;
	}
}

void ListAsSLL::push_back(Object *object){

}
void ListAsSLL::pop_back(){

}

Object *ListAsSLL::at(size_t i){
	return NULL;
}
