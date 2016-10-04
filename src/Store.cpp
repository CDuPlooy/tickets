#include "Store.h"
#include "Debug.h"
#include "ListAsSLL.h"
#include "ListAsDLL.h"
#include "ListAsVector.h"
#include "ListAsDynamicArray.h"

Store::Store( short choice ){
      switch (choice) {
            case CSLL:{
                  container = new ListAsSLL();
                  break;
            }
            case CDLL:{
                  container = new ListAsDLL();
                  break;
            }
            case CVECTOR:{
                  container = new ListAsVector();
                  break;
            }
            case CDYNARR:{
                  container = new ListAsDynamicArray();
                  break;
            }
            default:
                  container = new ListAsVector();
      }
}

int Store::compareTo(Object const &) const{
      return 1;
}

Store::~Store(){
      delete container;
}

//Overloaded Functions
bool Store::isNull(void) const{
      return false;
}

int Store::compare(Object const &) const{
      return 1;
}

void Store::print(std::ostream &out) const{
      out << "Store";
}

std::string Store::getId() const{
      return "Store";
}

//Iterator implementaion:
Object *Store::getCurrent(){  //Executes fours times for CVECTOR
      return container->getCurrent();
}

void Store::next(){
      container->next();
}

void Store::previous(){
      container->previous();
}

void Store::push_back(Object *obj){
            container->push_back(obj);
}

void Store::pop_back(){
      container->pop_back();
}

bool Store::isAtEnd(){
      return container->isAtEnd();
}
