
#include "Object.h"
#include "ListAsDLL.h"


ListAsDLL::~ListAsDLL(){

}
ListAsDLL::ListAsDLL(){

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
