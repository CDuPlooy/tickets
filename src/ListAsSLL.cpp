
#include "Object.h"
#include "ListAsSLL.h"


ListAsSLL::~ListAsSLL(){

}
ListAsSLL::ListAsSLL(){

}

bool ListAsSLL::isNull(void) const{

}
int ListAsSLL::compare(Object const &) const{

}
void ListAsSLL::print(std::ostream &out) const{
      out << "Marker:Unsure";
}
std::string ListAsSLL::getId() const{
      return "ListAsSLL";
}
