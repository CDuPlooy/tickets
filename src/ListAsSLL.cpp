
#include "Object.h"
#include "ListAsSLL.h"


ListAsSLL::~ListAsSLL(){

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
