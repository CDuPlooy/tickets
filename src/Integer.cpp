#include "Integer.h"

//Constructors
Integer::Integer(){
      _internal = 0;
}

Integer::Integer(int a){
      _internal = a;
}

//Overloaded Functions
int Integer::compareTo(Object const &) const{
      return -2; //Marker:Unsure
}

bool Integer::isNull(void) const{
      return false;
}

int Integer::compare(Object const &) const{
      return -1; //Marker:Unsure
}

void Integer::print(std::ostream &out) const{
      out << "Integer (" << this << ")\n";
      out << "_internal : " << _internal << std::endl;
}


std::string Integer::getId() const{
      return "Integer";
}

//Overloaded Operators
Integer Integer::operator=(int a){
      return Integer(a);
}

bool Integer::operator==(Integer &i){
      return i._internal == this->_internal;
}

bool Integer::operator<=(Integer &i){
      return i._internal <= this->_internal;
}

bool Integer::operator>=(Integer &i){
      return i._internal >= this->_internal;
}

bool Integer::operator!=(Integer &i){
      return i._internal != this->_internal;
}

bool Integer::operator==(int i){
      return i == this->_internal;
}

bool Integer::operator<=(int i){
      return i <= this->_internal;
}

bool Integer::operator>=(int i){
      return i >= this->_internal;
}

bool Integer::operator!=(int i){
      return i != this->_internal;
}
