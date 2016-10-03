#include "Container.h"


Container::Container(){

}

Container::~Container(){

}


int Container::compareTo(Object const &) const{
      return -1;        //Marker:Unsure
}


bool Container::isNull(void) const{
      return false;
}

int Container::compare(Object const &a) const{
      return -1;        //Marker:Unsure
}

void Container::print(std::ostream &out) const{
      out << "Container (" << this << ")\n";
}
std::string Container::getId() const{
      return "Container";
}
