#include "ListAsVector.h"
#include <vector>
//Constructors
ListAsVector::~ListAsVector(){
      delete objectVector;
}
ListAsVector::ListAsVector(){
      objectVector = new std::vector<Object *>();
      nCurrent = 0;
}
//Overloaded Functions
int ListAsVector::compareTo(Object const &) const{
      return -1; //Marker:Unsure
}
bool ListAsVector::isNull(void) const{
      return false;
}
int ListAsVector::compare(Object const &) const{
      return -1; //Marker:Unsure
}
void ListAsVector::print(std::ostream &out) const{
      out << "ListAsVector ("<< this << ")\n";
      out << "Elements: " << objectVector->size() << std::endl;
}
std::string ListAsVector::getId() const{
      return "ListAsVector";
}

void ListAsVector::push_back(Object *object){
      objectVector->push_back(object);
}
void ListAsVector::pop_back(){
      objectVector->pop_back();
}

Object *ListAsVector::at(size_t i){
      return objectVector->at(i);
}

void ListAsVector::setCurrent(Object *object){
      current = object;
}

Object *ListAsVector::getCurrent(){
      return objectVector->at(nCurrent);
}

void ListAsVector::add(Object *object){
      push_back(object);
}

void ListAsVector::next(){
      current = objectVector->at(nCurrent++);
}

void ListAsVector::previous(){
      current = objectVector->at(nCurrent--);
}
