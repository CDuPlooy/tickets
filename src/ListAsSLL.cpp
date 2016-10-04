#include "Object.h"
#include "ListAsSLL.h"
#include "Debug.h"

ListAsSLL::~ListAsSLL(){
		Node *temp = head;
		while( temp ){
			Node *old = temp;
			temp = temp->getNext();
			delete old;
		}
}
ListAsSLL::ListAsSLL(){
	currentl = NULL;
	head = NULL;
	_size = 0;
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


void ListAsSLL::add( Object *value ){
	Node *node = new Node();
	node->set(value);
	node->setNext(NULL);

	if( !head ){
		head = node;
		currentl = node;
		return;
		}

	Node *temp = head;

	while( temp->getNext() )
		temp = temp->getNext();

	temp->setNext(node);
	_size++;
	//currentl = node;
}
bool ListAsSLL::isAtEnd(){
	return ((Node *)currentl)== NULL;
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

void ListAsSLL::remove(Object *object){
	if(head == NULL)
		return;
	if(head->getNext() == NULL){
		if(head->get() == object)
			delete head;
		head = NULL;
		_size--;
		return;
	}
	bool found = false;
	Node *prev = head;
	Node *temp = head;
	while( temp ){
		if( object == temp ){
			found = true;
			break;
		}
		prev = temp;
		temp = temp->getNext();
		}

	if(found){
		if(temp->getNext() == NULL){
			_size--;
			delete temp;

			prev->setNext(NULL);
			head = prev;
			return;
		}
		else if(temp == head){
			if( temp->getNext() != NULL ){
				head = temp->getNext();
			}
			else
				head = NULL;
			_size--;

			delete temp;
			return;
		}
		else{

		}

		prev->setNext(temp->getNext());
		current  = temp->getNext();
		delete temp;
		return;
	}
}

void ListAsSLL::setCurrent(Object *object){
	currentl = object;
}

Object *ListAsSLL::getCurrent(){
	if(isAtEnd())
		return NULL;
	return ((Node *)currentl)->get();
}

void ListAsSLL::next(){
	currentl = ((Node *)currentl)->getNext();	//Marker:Dangerous,Unsure
}

void ListAsSLL::previous(){
	Node *temp = head;
	size_t size = _size;
	if(_size == 0){
		currentl = NULL;
		return;
	}

	while( temp->getNext() ){
		temp = temp->getNext();
		size--;
		if( size == _size - 1 ){
			currentl  = ((Node *)currentl)->get();
			return;
			}
		}
	currentl = NULL;
}

void ListAsSLL::push_back(Object *object) {
	add(object);
}

void ListAsSLL::pop_back(){
	Node *temp = head;
	while( temp->getNext() ){
		temp = temp->getNext();
	}
	remove(temp);
}

Object *ListAsSLL::at(size_t i){
	Node *temp = head;
	size_t j = 0;
	while( temp->getNext() ){
		temp = temp->getNext();
		if(j++ == i)
			return temp;
	}
	return NULL;
}
