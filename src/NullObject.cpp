/*
Connor Armand Du Plooy
u16169532
*/
#include "NullObject.h"
NullObject *NullObject::_singleton = NULL;

NullObject::NullObject(){

}

NullObject::~NullObject(){

}

int NullObject::compareTo(Object const &) const{
      return -1;        //Marker:Unsure
}


bool NullObject::isNull(void) const{
      return true;
}

int NullObject::compare(Object const &a) const{
      return -1;        //Marker:Unsure
}

void NullObject::print(std::ostream &out) const{
      out << "NullObject (" << this << ")\n";
}

NullObject* NullObject::getSingleton(){
      if(!NullObject::_singleton)
            NullObject::_singleton = new NullObject();

      return NullObject::_singleton;
}

void NullObject::setSingleton(NullObject *singleton){
      NullObject::_singleton = singleton;
}

std::string NullObject::getId() const{
      return "NullObject";
}
