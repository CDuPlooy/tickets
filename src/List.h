#ifndef LIST_H
#define LIST_H
#include "Object.h"
class List : public Object{
protected:
      int compareTo(Object const &) const =0;
public:
      //Constructors
      ~List();
      List();
      //Overloaded Functions
      bool isNull(void) const = 0;
      int compare(Object const &) const = 0;
      void print(std::ostream & = std::cout) const = 0;
      std::string getId() const = 0;
      //Unique Functions
};
#endif