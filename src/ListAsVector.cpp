#include "ListAsVector.h"
#include <vector>
//Constructors
ListAsVector::~ListAsVector(){
      delete objectVector;
}
ListAsVector::ListAsVector(){
      objectVector = new std::vector<Object *>();
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
      delete objectVector->at(objectVector->size());
      objectVector->pop_back();
}

Object *ListAsVector::at(size_t i){
      return objectVector->at(i);
}
