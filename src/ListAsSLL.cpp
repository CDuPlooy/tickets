
#include "Object.h"
#include "ListAsSLL.h"


ListAsSLL::~ListAsSLL(){
	head = NULL;
}
ListAsSLL::ListAsSLL(){
	current = NULL;
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
		return;
		}

	Node *temp = head;
	while( temp->getNext() )
		temp = temp->getNext();
	temp->setNext(node);
	current = node;
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
	}
	bool found = false;
	Node *prev = head;
	Node *temp = head;
	while( temp ){
		if( object == temp->get() ){
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
		current  = temp->getNext();
		delete temp;
		return;
	}
}

void ListAsSLL::setCurrent(Object *object){
	current = object;
}

Object *ListAsSLL::getCurrent(){
	return current;
}

void ListAsSLL::next(){
	current = ((Node *)current)->getNext();	//Marker:Dangerous,Unsure
}

void ListAsSLL::previous(){
	int a = 1 + 1;
	a+=1;			//Previous for list as SSL should have no implementation
}

void ListAsSLL::push_back(Object *object) {
	add(object);
}

void ListAsSLL::pop_back(){
	Node *temp = head;
	while( temp ){
		temp = temp->getNext();
	}
	remove(temp);
}

Object *ListAsSLL::at(size_t i){
	Node *temp = head;
	size_t j = 0;
	while( temp ){
		temp = temp->getNext();
		if(j++ == i)
			return temp;
	}
	return NULL;
}
