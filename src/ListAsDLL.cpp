#include "Debug.h"
#include "Object.h"
#include "ListAsDLL.h"


ListAsDLL::~ListAsDLL(){
	NodeDouble *temp = head;
	while( temp ){
		Node *old = temp;
		temp = temp->getNext();
		delete old;
	}
}
ListAsDLL::ListAsDLL(){
	_size = 0;
	currentl = NULL;
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

bool ListAsDLL::isAtEnd(){
	return ((NodeDouble *)currentl) == NULL;
}

void ListAsDLL::add( Object *value ){
	NodeDouble *node = new NodeDouble();
	node->set(value);
	node->setNext(NULL);
	node->setPrev(NULL);

	if( !head ){
		head = node;
		currentl = node;
		_size++;
		return;
		}

	NodeDouble *current = head;
	while( current->getNext() )
		current = current->getNext();
	current->setNext(node);
	node->setPrev(current);
	node->setNext(NULL);
	// currentl = node;
	_size++;

}

void ListAsDLL::previous(){

		NodeDouble *temp = head;
		size_t size = _size;
		if(_size == 0){
			currentl = NULL;
			return;
		}

		while( temp->getNext() ){
			temp = temp->getNext();
			size--;
			if( size == _size - 1 ){
				currentl  = ((NodeDouble *)currentl)->get();
				return;
				}
			}



		currentl = NULL;
}

void ListAsDLL::next(){
	currentl = ((NodeDouble *)currentl)->getNext();
}

void ListAsDLL::push_back(Object *object) {
	add(object);
}

void ListAsDLL::pop_back(){
	Node *temp = head;
	size_t size = _size;
	if(_size == 0){
		currentl = NULL;
		return;
	}
	while( temp ){
		temp = temp->getNext();
		size--;
		if( size == _size - 1 ){
			currentl  = ((Node *)currentl)->get();
			return;
			}
		}
	currentl = NULL;
}

Object *ListAsDLL::at(size_t i){
	NodeDouble *temp = head;
	size_t j = 0;
	while( temp ){
		temp = temp->getNext();
		if(j++ == i)
			return temp;
	}
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

void ListAsDLL::remove(Object *value){
	if(head == NULL){
		_size = 0;
		return;
	}
	if(head->getNext() == NULL){
		if(head->get() == value){
			_size = 0;
			delete head;
		}
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
		_size--;
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

void ListAsDLL::setCurrent(Object *object){
	currentl = object;
}

Object *ListAsDLL::getCurrent(){
		if(isAtEnd())
			return NULL;
		return ((NodeDouble *)currentl)->get();
}
